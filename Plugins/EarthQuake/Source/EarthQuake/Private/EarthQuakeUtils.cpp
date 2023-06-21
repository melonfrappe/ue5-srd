// Copyright Nippon Koei Co., Ltd. All Rights Reserved.

#include "EarthQuakeUtils.h"
#include <Engine/World.h>
#include <GameFramework/Actor.h>
#include <Landscape.h>
#include <Engine.h>
#include "Containers/Map.h"

bool FEarthQuakeUtils::IsForceUseCesiumGeoreference = false;


const TCHAR* FEarthQuakeUtils::WhiteSpace[] =
{
  TEXT(" "),
  TEXT("\t"),
  TEXT("\n"),
};
const int32 FEarthQuakeUtils::NumWhiteSpace = UE_ARRAY_COUNT(WhiteSpace);



//##### 
//
UWorld* FEarthQuakeUtils::GetWorld(UObject *Object)
{
  return Object->GetWorld();
}

//************************************
//  convertProjectPath
//************************************
FString FEarthQuakeUtils::convertProjectPath(FString& path)
{
  FString projDir = FPaths::ProjectDir();
  int32 projDirIdx = path.Find(projDir);
  if (projDirIdx >= 0)
  {
    return FString(TEXT("/")) + path.Mid(projDirIdx + projDir.Len());
  }
  return path;
}

//************************************
//  getFileFullPath
//************************************
FString FEarthQuakeUtils::getFileFullPath(FString& path)
{
  if (path.Left(1) == TEXT("/") ||
    path.Left(1) == TEXT("\\"))
  {
    return FPaths::ProjectDir() + path;
  }
  return path;
}

//************************************
//  getFilePath
//************************************
FString FEarthQuakeUtils::getFilePath(FString& path)
{
  int32 index;
  if (path.FindLastChar(TEXT('/'), index) ||
    path.FindLastChar(TEXT('\\'), index))
  {
    return path.Left(index);
  }
  return path + "/";
}



//************************************
bool FEarthQuakeUtils::getFloatParam(FString& paramString, TCHAR* tag, float& out)
{
  int32 findIdx = paramString.Find(tag);
  if (findIdx >= 0)
  {
    out = FCString::Atof(*paramString.Mid(findIdx + FCString::Strlen(tag)));
    return true;

  }
  return false;
}

//************************************
bool FEarthQuakeUtils::getStringParam(FString& paramString, TCHAR* tag, FString& out)
{
  int32 findIdx = paramString.Find(tag);
  if (findIdx >= 0)
  {
    out = paramString.Mid(findIdx + FCString::Strlen(tag));
    return true;
  }
  return false;
}
