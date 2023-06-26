// Fill out your copyright notice in the Description page of Project Settings.


#include "EarthQuakeNiagaraActorBase.h"
#include "EarthQuakeUtils.h"
#include "NiagaraComponent.h"
#include "RenderUtils.h"
#include "Engine/Texture2DDynamic.h"
#if WITH_EDITOR
#include "Misc/FileHelper.h"
#include "DesktopPlatformModule.h"
#include "EditorDirectories.h"
#include "Serialization/Csv/CsvParser.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "IContentBrowserSingleton.h"
#include "ContentBrowserModule.h"
#endif

#define LOCTEXT_NAMESPACE "EarthQuakeNiagaraActorBase"

//##### AEarthQuakeNiagaraActorBase
AEarthQuakeNiagaraActorBase::AEarthQuakeNiagaraActorBase(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
  InitializeDefaults();
}

//##### InitializeDefaults
void AEarthQuakeNiagaraActorBase::InitializeDefaults()
{
#if 0
  PrimaryActorTick.bCanEverTick = true;
  PrimaryActorTick.TickGroup = TG_LastDemotable;  // TG_PrePhysics;
  PrimaryActorTick.bStartWithTickEnabled = true;
  PrimaryActorTick.SetTickFunctionEnable(true);
  // bIsEditorOnlyActor = true;
  // bCanBeInCluster = (GetClass() == AHapWaterActor::StaticClass());
#endif
  PlayTime = 10;
  IdleTime = 5;

  // DebugMag = 0.0f;

  Colors.SetNum(4);
  Colors[0] = FLinearColor(1.0f,0.0f,0.0f);
  Colors[1] = FLinearColor(1.0f,1.0f,0.0f);
  Colors[2] = FLinearColor(0.0f,1.0f,0.0f);
  Colors[3] = FLinearColor(0.0f,0.0f,1.0f);

  /*
  DebugMode0 = 0;
  DebugMode1 = 0;
  DebugScale.X = 0.5f;
  DebugScale.Y = 0.25f;
  DebugScale.Z = 0.02f;
  DebugScale.W = 1.0f;
  */
}

//#### ShouldTickIfViewportsOnly
bool AEarthQuakeNiagaraActorBase::ShouldTickIfViewportsOnly() const
{
  return true;
}

//##### CreatePointCloudTexture_RenderThread
static void CreatePointCloudTexture_RenderThread(FTexture2DDynamicResource* TextureResource,const TArray<FEQPixelData> Bitmap)
{
  check(IsInRenderingThread());

  if (TextureResource)
  {
    FRHITexture2D* TextureRHI = TextureResource->GetTexture2DRHI();

    int32 Width = TextureRHI->GetSizeX();
    int32 Height = TextureRHI->GetSizeY();

    uint32 DestStride = 0;
    uint8* DestData = reinterpret_cast<uint8*>(RHILockTexture2D(TextureRHI,0,RLM_WriteOnly,DestStride,false,false));

    for (int32 y = 0; y < Height; y++)
    {
      FEQPixelData* DestPtr = (FEQPixelData*)&DestData[((int64)Height - 1 - y) * DestStride];

      const FEQPixelData* SrcPtr = &((FEQPixelData*)(Bitmap.GetData()))[((int64)Height - 1 - y) * Width];
      for (int32 x = 0; x < Width; x++)
      {
        *DestPtr++ = *SrcPtr++;
      }
    }

    RHIUnlockTexture2D(TextureRHI,0,false,false);
  }
}

//##### CreatePointCloudTexture
void AEarthQuakeNiagaraActorBase::CreatePointCloudTexture(const TArray<FEQPixelData>& Bitmap,int32 Width,int32 Height)
{
  if (Bitmap.Num() != Width * Height)
  {
    UE_LOG(LogTemp,Error,TEXT("Bitmap size does not match width and height."));
    return;
  }

  // FTexture2DDynamicCreateInfo(EPixelFormat InFormat = PF_B8G8R8A8,bool InIsResolveTarget = false,bool InSRGB = true,TextureFilter InFilter = TF_Default,ESamplerAddressMode InSamplerAddressMode = AM_Wrap)
  FTexture2DDynamicCreateInfo CreateInfo(PIXEL_FORMAT, false, false, TF_Nearest, AM_Clamp);
  PointCloudTexture = UTexture2DDynamic::Create(Width,Height,CreateInfo);
  if (!PointCloudTexture)
  {
    UE_LOG(LogTemp,Error,TEXT("Failed to create dynamic texture."));
    return;
  }
#if WITH_EDITOR
  PointCloudTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
  PointCloudTexture->DeferCompression = false;
  PointCloudTexture->CompressionNoAlpha = false;
  PointCloudTexture->CompressionNone = true;
#endif
  PointCloudTexture->CompressionSettings = TC_HDR; // TC_Displacementmap;
  PointCloudTexture->NeverStream = true;
  PointCloudTexture->SRGB = false;
  PointCloudTexture->UpdateResource();

  FTexture2DDynamicResource* TextureResource = static_cast<FTexture2DDynamicResource*>(PointCloudTexture->GetResource());
  if (TextureResource)
  {
    ENQUEUE_RENDER_COMMAND(FWriteRawDataToTexture)(
      [TextureResource,Bitmap](FRHICommandListImmediate& RHICmdList)
      {
        CreatePointCloudTexture_RenderThread(TextureResource,Bitmap);
      });
  }

  /*
    PointCloudStaticTexture = UTexture2D::CreateTransient(Width,Height,PF_A32B32G32R32F);
    if (!PointCloudStaticTexture) return;

    void *Data = PointCloudStaticTexture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
    FMemory::Memcpy(Data,Bitmap.GetData(),Bitmap.Num() * sizeof(FEQPixelData));
    PointCloudStaticTexture->GetPlatformData()->Mips[0].BulkData.Unlock();

    PointCloudStaticTexture->UpdateResource();
  */
}

static void calcDateTime(int64 Time, FString &DateTimeStr)
{
  FDateTime DateTime(Time);
  DateTimeStr = DateTime.ToString(TEXT("%Y/%m/%d %H:%M:%S"));
}

void AEarthQuakeNiagaraActorBase::GetMinTime(FString& DateTimeStr)
{
  calcDateTime(MinTime, DateTimeStr);
}

void AEarthQuakeNiagaraActorBase::GetMaxTime(FString& DateTimeStr)
{
  calcDateTime(MaxTime, DateTimeStr);
}

void AEarthQuakeNiagaraActorBase::GetPlayNowTime(FString& DateTimeStr)
{
  FNiagaraSystemInstanceControllerConstPtr NiagaraSystemInstanceControllerConstPtr = GetNiagaraComponent()->GetSystemInstanceController();
  if (NiagaraSystemInstanceControllerConstPtr.IsValid())
  {
    double age = NiagaraSystemInstanceControllerConstPtr->GetAge();
    int64 curTime = age / PlayTime * (MaxTime - MinTime) + MinTime;
    if (curTime > MaxTime) curTime = MaxTime;
    calcDateTime(curTime, DateTimeStr);
  }
}

//##### CreatePointCloud
void AEarthQuakeNiagaraActorBase::CreatePointCloud()
{
  NumPointCloud = PointCloud.Num();
  if (NumPointCloud <= 0)
  {
    return;
  }

  if (RelationEarthQuakeNiagaraActor == nullptr)
  {
    MinX = INT_MAX,MaxX = INT_MIN;
    MinY = INT_MAX,MaxY = INT_MIN;
    MinZ = INT_MAX,MaxZ = INT_MIN;
    MinTime = LLONG_MAX,MaxTime = LLONG_MIN;
    for (auto& PointData : PointCloud)
    {
      MinX = FMath::Min(MinX,PointData.x);
      MaxX = FMath::Max(MaxX,PointData.x);
      MinY = FMath::Min(MinY,PointData.y);
      MaxY = FMath::Max(MaxY,PointData.y);
      MinZ = FMath::Min(MinZ,PointData.z);
      MaxZ = FMath::Max(MaxZ,PointData.z);
      MinTime = FMath::Min(MinTime,PointData.time);
      MaxTime = FMath::Max(MaxTime,PointData.time);
    }
    SizeX = (MaxX - MinX) + 1;
    CentX = (MaxX + MinX) / 2;
    SizeY = (MaxY - MinY) + 1;
    CentY = (MaxY + MinY) / 2;
    SizeZ = (MaxZ - MinZ) + 1;
    CentZ = (MaxZ + MinZ) / 2;
    SizeMax = FMath::Max3(SizeX,SizeY,SizeZ);
  }
  else {
    MaxX = RelationEarthQuakeNiagaraActor->MaxX;
    MaxY = RelationEarthQuakeNiagaraActor->MaxY;
    MaxZ = RelationEarthQuakeNiagaraActor->MaxZ;
    MinX = RelationEarthQuakeNiagaraActor->MinX;
    MinY = RelationEarthQuakeNiagaraActor->MinY;
    MinZ = RelationEarthQuakeNiagaraActor->MinZ;
    SizeX = RelationEarthQuakeNiagaraActor->SizeX;
    SizeY = RelationEarthQuakeNiagaraActor->SizeY;
    SizeZ = RelationEarthQuakeNiagaraActor->SizeZ;
    CentX = RelationEarthQuakeNiagaraActor->CentX;
    CentY = RelationEarthQuakeNiagaraActor->CentY;
    CentZ = RelationEarthQuakeNiagaraActor->CentZ;
    SizeMax = RelationEarthQuakeNiagaraActor->SizeMax;
    MaxTime = RelationEarthQuakeNiagaraActor->MaxTime;
    MinTime = RelationEarthQuakeNiagaraActor->MinTime;
    PlayTime = RelationEarthQuakeNiagaraActor->PlayTime;
    IdleTime = RelationEarthQuakeNiagaraActor->IdleTime;
  }

  //============================================================================
  int64 siztime = MaxTime - MinTime;
  int32 PlayFrame = PlayTime * FPS30;

  TArray<TArray<FEQPixelData>> BitmapXY;
  BitmapXY.Empty(8192);
  TArray<FEQPixelData> BitmapX;
  BitmapX.Empty(8192);
  int64 curtime = 0;
  int64 curindex = 0;
  int32 maxSpawnCountPerFrame = 0;
  for (int32 curframe = 0; curframe < PlayFrame; ++curframe)
  {
    int64 nexttime = (siztime * (curframe + 1)) / PlayFrame;
    
    /*
    if (curframe <= 5 * FPS30)
    {
      nexttime = 0;
    }
    else if (curframe <= 9 * FPS30)
    {
      nexttime = (siztime * (5 * FPS30 + 1)) / PlayFrame;
    }
    else {
      nexttime = (siztime * (9 * FPS30 + 1)) / PlayFrame;
    }
    */
      
    float x32,y32,z32,w32;
    for (; curindex < PointCloud.Num(); )
    {
      auto& PointData = PointCloud[curindex];
      int64 time = PointData.time - MinTime;
      if (time < nexttime)
      {
        FEQPixelData Pixel;
        x32 = ((float)(PointData.x - CentX)) / (float)SizeMax;
        y32 = ((float)(PointData.y - CentY)) / (float)SizeMax;
        z32 = ((float)(PointData.z - CentZ)) / (float)SizeMax;
        if (FMath::Abs(x32) > 65000.0f || FMath::Abs(x32) > 65000.0f || FMath::Abs(x32) > 65000.0f)
        {
          UE_LOG(LogTemp,Error,TEXT("error F16 over x=%f y=%f z=%f"),x32,y32,z32);
        }
        w32 = (float)PointData.mag;
        // if (x32 < 0.0f || y32 < 0.0f || z32 < 0.0f || w32 < 0.0f)
        // {
        //  UE_LOG(LogTemp,Error,TEXT("error minus x=%f y=%f z=%f w=%f"), x32, y32, z32, w32);
        // }
        Pixel.R = FFloat16(x32);
        Pixel.G = FFloat16(y32);
        Pixel.B = FFloat16(z32);
        Pixel.A = FFloat16(w32);
        BitmapX.Add(Pixel);
        ++curindex;
      }
      else {
        maxSpawnCountPerFrame = FMath::Max(maxSpawnCountPerFrame,BitmapX.Num());
        BitmapXY.Add(BitmapX);
        BitmapX.Empty(8192);
        break;
      }
    }
  }
  if (!BitmapX.IsEmpty())
  {
    maxSpawnCountPerFrame = FMath::Max(maxSpawnCountPerFrame,BitmapX.Num());
    BitmapXY.Add(BitmapX);
    BitmapX.Empty();
  }
  

  int32 texsizex = EQ_TEXTURE_SIZEX;
  int32 texsizey = (NumPointCloud + (EQ_TEXTURE_SIZEX - 1)) / EQ_TEXTURE_SIZEX;

  SpawnCountArray.Empty(BitmapXY.Num());
  TArray<FEQPixelData> Bitmap;
  Bitmap.AddZeroed(texsizex * texsizey);
  int32 pos = 0;
  for (int32 y = 0; y < BitmapXY.Num(); ++y)
  {
    auto& Bitmap_X = BitmapXY[y];
    /* if (y == 0)
    {
      SpawnCountArray.Add(1000);
    } else */
    SpawnCountArray.Add(Bitmap_X.Num());
    for (int32 x = 0; x < Bitmap_X.Num(); ++x)
    {
      Bitmap[pos++] = Bitmap_X[x];
    }
  }
  // ParticleSpawnRate = maxSpawnCountPerFrame * FPS30;

  /*
  int32 numpoint = PointCloud.Num();
  int32 texsizex = FMath::Sqrt(numpoint);
  if (texsizex & 1)
  {
    texsizex++;
  }
  int32 texsizey = texsizex;
  texsizey += 2;
  TArray<FEQPixelData> Bitmap;
  Bitmap.SetNumZeroed(texsizex * texsizey);
  int32 index = 0;

  for (auto& PointData : PointCloud)
  {
    auto& Pixel = Bitmap[index++];
    x32 = ((float)(PointData.x - centx)) / (float)sizemax;
    y32 = ((float)(PointData.y - centy)) / (float)sizemax;
    z32 = ((float)(PointData.z - centz)) / (float)sizemax;
    if (FMath::Abs(x32) > 65000.0f || FMath::Abs(x32) > 65000.0f || FMath::Abs(x32) > 65000.0f)
    {
      UE_LOG(LogTemp,Error,TEXT("error F16 over x=%f y=%f z=%f"),x32,y32,z32);
    }
    w32 = (float)PointData.mag;
    // if (x32 < 0.0f || y32 < 0.0f || z32 < 0.0f || w32 < 0.0f)
    // {
    //  UE_LOG(LogTemp,Error,TEXT("error minus x=%f y=%f z=%f w=%f"),x32,y32,z32,w32);
    // }
    Pixel.R = FFloat16(x32);
    Pixel.G = FFloat16(y32);
    Pixel.B = FFloat16(z32);
    Pixel.A = FFloat16(w32);
  }
  */


  EmitterLifeTime = (PlayFrame / FPS30) + IdleTime;

  CreatePointCloudTexture(Bitmap,texsizex,texsizey);

  ReceiveCreatePointCloud();
}

/*
  //============================================================================

  int32 numpoint = PointCloud.Num();
  int32 texsizex = FMath::Sqrt(numpoint);
  if (texsizex & 1)
  {
    texsizex++;
  }
  int32 texsizey = texsizex;
  texsizey += 2;
  TArray<FEQPixelData> Bitmap;
  Bitmap.SetNumZeroed(texsizex * texsizey);
  int32 index = 0;

  for (auto& PointData : PointCloud)
  {
    auto& Pixel = Bitmap[index++];

    float x,y,z,w;

    switch (DebugMode0)
    {
    case 0:
      x = (((float)PointData.x - centx)) / sizemax;
      y = (((float)PointData.y - centy)) / sizemax;
      z = (((float)PointData.z - centz)) / sizemax;
      w = ((float)PointData.mag + 1.0f);
      break;
    default:
      x = FMath::RandRange(-DebugScale.X,DebugScale.X);
      y = FMath::RandRange(-DebugScale.Y,DebugScale.Y);
      z = FMath::RandRange(-DebugScale.Z,DebugScale.Z);
      w = DebugScale.W;
    }
    switch (DebugMode1)
    {
    case 0:
      Pixel.R = FFloat16(x).Encoded;
      Pixel.G = FFloat16(y).Encoded;
      Pixel.B = FFloat16(z).Encoded;
      Pixel.A = FFloat16(w).Encoded;
      break;
    case 1:
      Pixel.B = FFloat16(x).Encoded;
      Pixel.G = FFloat16(y).Encoded;
      Pixel.R = FFloat16(z).Encoded;
      Pixel.A = FFloat16(w).Encoded;
      break;
    case 2:
      Pixel.A = FFloat16(x).Encoded;
      Pixel.R = FFloat16(y).Encoded;
      Pixel.G = FFloat16(z).Encoded;
      Pixel.B = FFloat16(w).Encoded;
    default:
      Pixel.A = FFloat16(x).Encoded;
      Pixel.B = FFloat16(y).Encoded;
      Pixel.G = FFloat16(z).Encoded;
      Pixel.R = FFloat16(w).Encoded;
      break;
    }
  }
*/

//##### PostEditChangeProperty
#if WITH_EDITOR
void AEarthQuakeNiagaraActorBase::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
  FProperty* PropertyThatChanged = PropertyChangedEvent.Property;
  if (PropertyThatChanged)
  {
    if (PropertyThatChanged->GetName() == TEXT("PointCloudPath"))
    {
    }
  }
  Super::PostEditChangeProperty(PropertyChangedEvent);
}

//##### OpenFileDialog
bool AEarthQuakeNiagaraActorBase::OpenFileDialog(const FString& DialogTitle,const FString& DefaultFile,FString& outFileName)
{
  TArray<FString> OpenFilenames;
  IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
  bool bOpened = false;
  int32 FilterIndex = -1;

  if (DesktopPlatform)
  {
    const void* ParentWindowWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);

    bOpened = DesktopPlatform->OpenFileDialog(
      ParentWindowWindowHandle,
      DialogTitle,
      FEditorDirectories::Get().GetLastDirectory(ELastDirectory::GENERIC_IMPORT),
      TEXT(""),
      DefaultFile,
      EFileDialogFlags::Multiple,
      OpenFilenames,
      FilterIndex
    );
  }

  if (!bOpened)
    return false;

  if (OpenFilenames.Num() == 0)
    return false;

  FEditorDirectories::Get().SetLastDirectory(ELastDirectory::GENERIC_IMPORT,OpenFilenames[0]);

  outFileName = OpenFilenames[0];
  return true;
}

//##### ReadPointCloud
void AEarthQuakeNiagaraActorBase::ReadPointCloud()
{
  FString filename = FEarthQuakeUtils::getFileFullPath(PointCloudPath);

  FString CSVFileContent;
  if (!FFileHelper::LoadFileToString(CSVFileContent,*filename))
  {
    UE_LOG(LogTemp,Error,TEXT("Failed to load CSV file: %s"),*filename);
    return;
  }

  FCsvParser CsvParser(CSVFileContent);
  const FCsvParser::FRows& Rows = CsvParser.GetRows();
  int32 RowIndex = 0;
  PointCloud.Empty();

  for (const TArray<const TCHAR*>& Row : Rows)
  {
    if (RowIndex == 0)
    {
    }
    else {
      FEQPointData PointData;
      PointData.x = FCString::Atoi(Row[0]);
      PointData.y = FCString::Atoi(Row[1]);
      PointData.z = FCString::Atoi(Row[2]);

      /* if (DebugMag >= 0.00001f)
        PointData.mag = DebugMag;
      else */
      PointData.mag = FCString::Atof(Row[3]);
      int32 date0 = FCString::Atoi(Row[4]),date = date0, date00 = date0;
      int32 time0 = FCString::Atoi(Row[5]),time = time0, time00 = time0;
      date /= 100;
      int32 day = date0 - (date * 100);
      date0 = date;
      date /= 100;
      int32 mon = date0 - (date * 100);
      uint16 yer = date;
      time /= 100;
      int32 dsec = time0 - (time * 100);
      time0 = time;
      time /= 100;
      int32 sec = time0 - (time * 100);
      time0 = time;
      time /= 100;
      int32 min = time0 - (time * 100);
      int32 hor = time;
      FDateTime DateTime(yer, mon, day, hor, min, sec, dsec*10);
      PointData.time = DateTime.GetTicks();

      PointCloud.Add(PointData);
    }
    ++RowIndex;
  }
  PointCloud.Sort([this](FEQPointData a,FEQPointData b) { return a.time < b.time; });
  CreatePointCloud();
}

//##### PointCloudPathOpen
void AEarthQuakeNiagaraActorBase::PointCloudPathOpen()
{
  if (OpenFileDialog(LOCTEXT("Open PointCloud CSV","Open PointCloud CSV").ToString(),TEXT("info file (*.csv)|*.csv|All files (*.*)|*.*"),PointCloudPath))
  {
    PointCloudPath = FEarthQuakeUtils::convertProjectPath(PointCloudPath);
    ReadPointCloud();
  }
}

//##### SavePointCloudTexture_RenderThread
static void SavePointCloudTexture_RenderThread(FRHITexture2D* TextureRHI,int32 Width,int32 Height,UTexture2D* SaveTexture)
{
  FTexture2DMipMap* Mip = new FTexture2DMipMap();
  SaveTexture->GetPlatformData()->Mips.Add(Mip);
  Mip->SizeX = Width;
  Mip->SizeY = Height;
  TArray<FEQPixelData>SaveTextureData;
  SaveTextureData.SetNum(Width*Height);

  uint32 DestStride = 0;
  uint8* DestData = reinterpret_cast<uint8*>(RHILockTexture2D(TextureRHI,0,RLM_ReadOnly,DestStride,false,false));

  uint8* DestDataY = DestData;
  FEQPixelData* TextureDataX = (FEQPixelData*)SaveTextureData.GetData();
  for (int32 y = 0; y < Height; y++)
  {
    FEQPixelData* DestDataX = (FEQPixelData*)DestDataY;
    for (int32 x = 0; x < Width; x++)
    {
      *TextureDataX++ = *DestDataX++;
    }
    DestDataY += DestStride;
  }
  RHIUnlockTexture2D(TextureRHI,0,false,false);

  SaveTexture->AddToRoot();
  SaveTexture->Source.Init(Width,Height,1,1,TSF_PIXEL_FORMAT,(uint8 *)SaveTextureData.GetData());
}

//##### SavePointCloudTexture
void AEarthQuakeNiagaraActorBase::SavePointCloudTexture()
{
  if (PointCloudTexture == nullptr)
    return;

  FSaveAssetDialogConfig SaveAssetDialogConfig;
  SaveAssetDialogConfig.DialogTitleOverride = FText::FromString(FString(TEXT("SaveDownloadImage")));
  SaveAssetDialogConfig.DefaultPath = TEXT("");
  SaveAssetDialogConfig.DefaultAssetName = TEXT("test");
  SaveAssetDialogConfig.ExistingAssetPolicy = ESaveAssetDialogExistingAssetPolicy::AllowButWarn;

  FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
  FString SaveObjectPath = ContentBrowserModule.Get().CreateModalSaveAssetDialog(SaveAssetDialogConfig);
  if (!SaveObjectPath.IsEmpty())
  {
    const FString SavePackageName = FPackageName::ObjectPathToPackageName(SaveObjectPath);
    const FString SavePackagePath = FPaths::GetPath(SavePackageName);
    const FString SaveAssetName = FPaths::GetBaseFilename(SavePackageName);

    // PointCloudTexture->StaticRegisterNativesUObject();

    FTexture2DDynamicResource* TextureResource = static_cast<FTexture2DDynamicResource*>(PointCloudTexture->GetResource());
    if (TextureResource)
    {
      FRHITexture2D* TextureRHI = TextureResource->GetTexture2DRHI();
      int32 Width = TextureRHI->GetSizeX();
      int32 Height = TextureRHI->GetSizeY();

      FString PackagePath = SavePackageName;
      FString AbsolutePackagePath = SavePackagePath;		// FPaths::ProjectContentDir() + TEXT("/LoadedTexture/");
      // FPackageName::RegisterMountPoint(PackagePath, AbsolutePackagePath);
      UPackage* Package = CreatePackage(*PackagePath);
      Package->FullyLoad();

      // FName TextureName = MakeUniqueObjectName(Package, UTexture2D::StaticClass(), FName(*SaveAssetName));
      FName TextureName = FName(*SaveAssetName);
      UTexture2D* SaveTexture = NewObject<UTexture2D>(Package,TextureName,RF_Public | RF_Standalone);

      FTexturePlatformData* TexturePlatformData = new FTexturePlatformData();
      TexturePlatformData->SizeX = Width;
      TexturePlatformData->SizeY = Height;
      TexturePlatformData->PixelFormat = PIXEL_FORMAT;
      SaveTexture->SetPlatformData(TexturePlatformData);
      // FTexture2DDynamicCreateInfo(EPixelFormat InFormat = PF_B8G8R8A8,bool InIsResolveTarget = false,bool InSRGB = true,TextureFilter InFilter = TF_Default,ESamplerAddressMode InSamplerAddressMode = AM_Wrap)
      SaveTexture->Filter = TF_Nearest;
      SaveTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
      SaveTexture->CompressionSettings = TC_HDR; // TC_Displacementmap;
      SaveTexture->NeverStream = true;
      SaveTexture->DeferCompression = false;
      SaveTexture->CompressionNoAlpha = false;
      SaveTexture->CompressionNone = true;
      SaveTexture->SRGB = false;

      ENQUEUE_RENDER_COMMAND(FAddWriteRawDataToTexture)(
        [TextureRHI,Width,Height,SaveTexture](FRHICommandListImmediate& RHICmdList)
        {
          SavePointCloudTexture_RenderThread(TextureRHI,Width,Height,SaveTexture);
        });
      FlushRenderingCommands();
      SaveTexture->UpdateResource();
      SaveTexture->AddToRoot();

      Package->MarkPackageDirty();
      // FAssetRegistryModule::AssetCreated(SaveTexture);

      FString PackageFilename = FPackageName::LongPackageNameToFilename(PackagePath,FPackageName::GetAssetPackageExtension());
      // FString PackageFilename = FPaths::ProjectContentDir() + PackagePath + FPackageName::GetAssetPackageExtension();
      FSavePackageArgs SaveArgs;
      SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
      SaveArgs.Error = GError;
      // SaveArgs.Conform = nullptr;
      SaveArgs.bForceByteSwapping = true;
      SaveArgs.bWarnOfLongFilename = true;
      SaveArgs.SaveFlags = SAVE_NoError;

      UPackage::SavePackage(Package,SaveTexture,*PackageFilename,SaveArgs);
      Package->SetDirtyFlag(true);
    }
  }
}
#endif

