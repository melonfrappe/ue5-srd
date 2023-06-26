// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraActor.h"
#include "Engine/DataTable.h"
#include "Misc/DateTime.h"
#include "EarthQuakeNiagaraActorBase.generated.h"

#define FPS30 30
#define FPS30SEC (1.0f / FPS30)
#define EQ_TEXTURE_SIZEX 1024

class UTexture2DDynamic;

USTRUCT(BlueprintType)
struct FEQPointData
{
  GENERATED_BODY()
  FEQPointData() {}
  UPROPERTY(BlueprintReadOnly,Category = "EarthQuakeParam|PointData")
    int32 x;
  UPROPERTY(BlueprintReadOnly,Category = "EarthQuakeParam|PointData")
    int32 y;
  UPROPERTY(BlueprintReadOnly,Category = "EarthQuakeParam|PointData")
    int32 z;
  UPROPERTY(BlueprintReadOnly,Category = "EarthQuakeParam|PointData")
    float mag;
  UPROPERTY(BlueprintReadOnly,Category = "EarthQuakeParam|PointData")
    int64 time;
};


#define PIXEL_FORMAT PF_FloatRGBA   // PF_A16B16G16R16
#define TSF_PIXEL_FORMAT ETextureSourceFormat::TSF_RGBA16F
#define PIXEL_TYPE uint16

struct FEQPixelData : public FFloat16Color
{
};

/**
 * 
 */
UCLASS(hideCategories = (Transform, Nigara, Activation,Lighting, Attachment, Randomness, Parameters, Materials, Compilation, HLOD, Renderring, Components, Navigation, Tags, Cooking, Replication, Actor, Advanced, LOD, Collision, Input,Game, "Game|Damage"),ComponentWrapperClass)
class EARTHQUAKE_API AEarthQuakeNiagaraActorBase : public ANiagaraActor
{
	GENERATED_BODY()

#if WITH_EDITORONLY_DATA
private:
  bool OpenFileDialog(const FString& DialogTitle,const FString& DefaultFile,FString& outFileName);
public:
  virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
  AEarthQuakeNiagaraActorBase(const FObjectInitializer& ObjectInitializer);
  void InitializeDefaults();
  virtual bool ShouldTickIfViewportsOnly() const override;
  UFUNCTION(BlueprintImplementableEvent,meta = (DisplayName = "ConstructOverlap"),Category = "EarthQuakeParam")
    void ReceiveCreatePointCloud();
  UFUNCTION(BlueprintCallable,Category = "EarthQuakeParam")
    void GetMinTime(FString& DateTimeStr);
  UFUNCTION(BlueprintCallable,Category = "EarthQuakeParam")
    void GetMaxTime(FString& DateTimeStr);
  UFUNCTION(BlueprintCallable,Category = "EarthQuakeParam")
    void GetPlayNowTime(FString& DateTimeStr);
  void CreatePointCloudTexture(const TArray<FEQPixelData>& Bitmap,int32 Width,int32 Height);
  UFUNCTION(BlueprintCallable,CallInEditor,Category = "EarthQuakeParam")
    virtual void CreatePointCloud();
#if WITH_EDITORONLY_DATA
  UFUNCTION(BlueprintCallable,Category = "EarthQuakeParam")
    virtual void ReadPointCloud();
  UFUNCTION(BlueprintCallable,CallInEditor,Category = "EarthQuakeParam")
    virtual void PointCloudPathOpen();
  UFUNCTION(BlueprintCallable,CallInEditor,Category = "EarthQuakeParam")
    virtual void SavePointCloudTexture();
#endif

public:
  UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam")
    FString PointCloudPath;
  UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam")
    AEarthQuakeNiagaraActorBase *RelationEarthQuakeNiagaraActor;
  UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam")
    float PlayTime;
  UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam")
    float IdleTime;
  UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam")
    TArray<FLinearColor> Colors;
  UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam")
    float DebugMag;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    float EmitterLifeTime;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 MinX;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 MaxX;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 MinY;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 MaxY;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 MinZ;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 MaxZ;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int64 MinTime;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int64 MaxTime;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 SizeX;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 CentX;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 SizeY;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 CentY;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 SizeZ;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 CentZ;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam|NotEdit")
    int32 SizeMax;
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Transient,Category = "EarthQuakeParam|NotEdit")
    int32 NumPointCloud;

  UPROPERTY(BlueprintReadOnly,Category = "EarthQuakeParam")
    TArray<FEQPointData> PointCloud;

  UPROPERTY(BlueprintReadOnly,Category = "EarthQuakeParam")
    TArray<int32> SpawnCountArray;

  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Transient,Category = "EarthQuakeParam")
    UTexture2DDynamic* PointCloudTexture;

  // UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "EarthQuakeParam")
  //  UTexture2D* PointCloudStaticTexture;
};
