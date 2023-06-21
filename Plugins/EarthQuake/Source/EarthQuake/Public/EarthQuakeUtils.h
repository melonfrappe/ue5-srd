// Copyright Nippon Koei Co., Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"

class UWorld;
class UObject;

struct EARTHQUAKE_API FEarthQuakeUtils
{
  static UWorld* GetWorld(UObject* Object);
  static FString convertProjectPath(FString& path);
  static FString getFileFullPath(FString& path);
  static FString getFilePath(FString& path);
  static bool getFloatParam(FString& paramString, TCHAR* tag, float& out);
  static bool getStringParam(FString& paramString, TCHAR* tag, FString& out);

  static const TCHAR* FEarthQuakeUtils::WhiteSpace[];
  static const int32 NumWhiteSpace;
  static bool IsForceUseCesiumGeoreference;
};
