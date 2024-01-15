// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Classes/Blueprint/SRDisplayManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSRDisplayManager() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	SRDISPLAYMODULE_API UClass* Z_Construct_UClass_ASRDisplayManager();
	SRDISPLAYMODULE_API UClass* Z_Construct_UClass_ASRDisplayManager_NoRegister();
	SRDISPLAYMODULE_API UEnum* Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType();
	SRDISPLAYMODULE_API UEnum* Z_Construct_UEnum_SRDisplayModule_EGizmoSize();
	SRDISPLAYMODULE_API UEnum* Z_Construct_UEnum_SRDisplayModule_EScalingMode();
	UPackage* Z_Construct_UPackage__Script_SRDisplayModule();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECrosstalkCorrectionType;
	static UEnum* ECrosstalkCorrectionType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECrosstalkCorrectionType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECrosstalkCorrectionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType, (UObject*)Z_Construct_UPackage__Script_SRDisplayModule(), TEXT("ECrosstalkCorrectionType"));
		}
		return Z_Registration_Info_UEnum_ECrosstalkCorrectionType.OuterSingleton;
	}
	template<> SRDISPLAYMODULE_API UEnum* StaticEnum<ECrosstalkCorrectionType>()
	{
		return ECrosstalkCorrectionType_StaticEnum();
	}
	struct Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics::Enumerators[] = {
		{ "ECrosstalkCorrectionType::GRADATION_CORRECTION_MEDIUM", (int64)ECrosstalkCorrectionType::GRADATION_CORRECTION_MEDIUM },
		{ "ECrosstalkCorrectionType::GRADATION_CORRECTION_ALL", (int64)ECrosstalkCorrectionType::GRADATION_CORRECTION_ALL },
		{ "ECrosstalkCorrectionType::GRADATION_CORRECTION_HIGH_PRECISE", (int64)ECrosstalkCorrectionType::GRADATION_CORRECTION_HIGH_PRECISE },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics::Enum_MetaDataParams[] = {
		{ "GRADATION_CORRECTION_ALL.Comment", "/*\n\x09""Corrects crosstalk and make it less noticeable at all gradation.\n\x09GPU load will be higher than that of \"Medium gradation correction\".\n\x09*/" },
		{ "GRADATION_CORRECTION_ALL.DisplayName", "Mid" },
		{ "GRADATION_CORRECTION_ALL.Name", "ECrosstalkCorrectionType::GRADATION_CORRECTION_ALL" },
		{ "GRADATION_CORRECTION_ALL.ToolTip", "Corrects crosstalk and make it less noticeable at all gradation.\nGPU load will be higher than that of \"Medium gradation correction\"." },
		{ "GRADATION_CORRECTION_HIGH_PRECISE.Comment", "/*\n\x09""Corrects crosstalk at all gradation.\n\x09""Crosstalk will be less noticeable than \"All gradation correction\".\n\x09GPU load will be higher than when \"All gradation correction\".\n\x09*/" },
		{ "GRADATION_CORRECTION_HIGH_PRECISE.DisplayName", "High" },
		{ "GRADATION_CORRECTION_HIGH_PRECISE.Name", "ECrosstalkCorrectionType::GRADATION_CORRECTION_HIGH_PRECISE" },
		{ "GRADATION_CORRECTION_HIGH_PRECISE.ToolTip", "Corrects crosstalk at all gradation.\nCrosstalk will be less noticeable than \"All gradation correction\".\nGPU load will be higher than when \"All gradation correction\"." },
		{ "GRADATION_CORRECTION_MEDIUM.Comment", "/*\n\x09""Corrects crosstalk and make it less noticeable at medium gradation.\n\x09GPU load will be a little higher than when crosstalk correction is not used.\n\x09*/" },
		{ "GRADATION_CORRECTION_MEDIUM.DisplayName", "Low" },
		{ "GRADATION_CORRECTION_MEDIUM.Name", "ECrosstalkCorrectionType::GRADATION_CORRECTION_MEDIUM" },
		{ "GRADATION_CORRECTION_MEDIUM.ToolTip", "Corrects crosstalk and make it less noticeable at medium gradation.\nGPU load will be a little higher than when crosstalk correction is not used." },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SRDisplayModule,
		nullptr,
		"ECrosstalkCorrectionType",
		"ECrosstalkCorrectionType",
		Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType()
	{
		if (!Z_Registration_Info_UEnum_ECrosstalkCorrectionType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECrosstalkCorrectionType.InnerSingleton, Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECrosstalkCorrectionType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EScalingMode;
	static UEnum* EScalingMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EScalingMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EScalingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SRDisplayModule_EScalingMode, (UObject*)Z_Construct_UPackage__Script_SRDisplayModule(), TEXT("EScalingMode"));
		}
		return Z_Registration_Info_UEnum_EScalingMode.OuterSingleton;
	}
	template<> SRDISPLAYMODULE_API UEnum* StaticEnum<EScalingMode>()
	{
		return EScalingMode_StaticEnum();
	}
	struct Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics::Enumerators[] = {
		{ "EScalingMode::SCALED_SIZE", (int64)EScalingMode::SCALED_SIZE },
		{ "EScalingMode::ORIGINAL_SIZE", (int64)EScalingMode::ORIGINAL_SIZE },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics::Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ORIGINAL_SIZE.DisplayName", "Original Size" },
		{ "ORIGINAL_SIZE.Name", "EScalingMode::ORIGINAL_SIZE" },
		{ "SCALED_SIZE.DisplayName", "Scaled Size" },
		{ "SCALED_SIZE.Name", "EScalingMode::SCALED_SIZE" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SRDisplayModule,
		nullptr,
		"EScalingMode",
		"EScalingMode",
		Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SRDisplayModule_EScalingMode()
	{
		if (!Z_Registration_Info_UEnum_EScalingMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EScalingMode.InnerSingleton, Z_Construct_UEnum_SRDisplayModule_EScalingMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EScalingMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGizmoSize;
	static UEnum* EGizmoSize_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EGizmoSize.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EGizmoSize.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SRDisplayModule_EGizmoSize, (UObject*)Z_Construct_UPackage__Script_SRDisplayModule(), TEXT("EGizmoSize"));
		}
		return Z_Registration_Info_UEnum_EGizmoSize.OuterSingleton;
	}
	template<> SRDISPLAYMODULE_API UEnum* StaticEnum<EGizmoSize>()
	{
		return EGizmoSize_StaticEnum();
	}
	struct Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics::Enumerators[] = {
		{ "EGizmoSize::ELF_SR1_SIZE", (int64)EGizmoSize::ELF_SR1_SIZE },
		{ "EGizmoSize::ELF_SR2_SIZE", (int64)EGizmoSize::ELF_SR2_SIZE },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics::Enum_MetaDataParams[] = {
		{ "ELF_SR1_SIZE.DisplayName", "ELF-SR1" },
		{ "ELF_SR1_SIZE.Name", "EGizmoSize::ELF_SR1_SIZE" },
		{ "ELF_SR2_SIZE.DisplayName", "ELF-SR2" },
		{ "ELF_SR2_SIZE.Name", "EGizmoSize::ELF_SR2_SIZE" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SRDisplayModule,
		nullptr,
		"EGizmoSize",
		"EGizmoSize",
		Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SRDisplayModule_EGizmoSize()
	{
		if (!Z_Registration_Info_UEnum_EGizmoSize.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGizmoSize.InnerSingleton, Z_Construct_UEnum_SRDisplayModule_EGizmoSize_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EGizmoSize.InnerSingleton;
	}
	void ASRDisplayManager::StaticRegisterNativesASRDisplayManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASRDisplayManager);
	UClass* Z_Construct_UClass_ASRDisplayManager_NoRegister()
	{
		return ASRDisplayManager::StaticClass();
	}
	struct Z_Construct_UClass_ASRDisplayManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShowCameraWindow_MetaData[];
#endif
		static void NewProp_ShowCameraWindow_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ShowCameraWindow;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CrosstalkCorrection_MetaData[];
#endif
		static void NewProp_CrosstalkCorrection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CrosstalkCorrection;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_CorrectionType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CorrectionType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CorrectionType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpatialClipping_MetaData[];
#endif
		static void NewProp_SpatialClipping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SpatialClipping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsSRRenderingActive_MetaData[];
#endif
		static void NewProp_IsSRRenderingActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSRRenderingActive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FarClip_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FarClip;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ScalingMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScalingMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ScalingMode;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_GizmoSize_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GizmoSize_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_GizmoSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoxColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_BoxColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DisplayColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LineThickness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LineThickness;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASRDisplayManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SRDisplayModule,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Blueprint/SRDisplayManager.h" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ShowCameraWindow_MetaData[] = {
		{ "Category", "SRDisplay|Tracking" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "If checked, a window opens and shows images captured by SRDisplay camera." },
	};
#endif
	void Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ShowCameraWindow_SetBit(void* Obj)
	{
		((ASRDisplayManager*)Obj)->ShowCameraWindow = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ShowCameraWindow = { "ShowCameraWindow", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ASRDisplayManager), &Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ShowCameraWindow_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ShowCameraWindow_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ShowCameraWindow_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CrosstalkCorrection_MetaData[] = {
		{ "Category", "SRDisplay|Rendering|Crosstalk Correction (ELF-SR1 exclusive)" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "If checked, crosstalk will be reduced." },
	};
#endif
	void Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CrosstalkCorrection_SetBit(void* Obj)
	{
		((ASRDisplayManager*)Obj)->CrosstalkCorrection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CrosstalkCorrection = { "CrosstalkCorrection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ASRDisplayManager), &Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CrosstalkCorrection_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CrosstalkCorrection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CrosstalkCorrection_MetaData)) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CorrectionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CorrectionType_MetaData[] = {
		{ "Category", "SRDisplay|Rendering|Crosstalk Correction (ELF-SR1 exclusive)" },
		{ "EditCondition", "CrosstalkCorrection" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "Crosstalk Correction level can be selected." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CorrectionType = { "CorrectionType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASRDisplayManager, CorrectionType), Z_Construct_UEnum_SRDisplayModule_ECrosstalkCorrectionType, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CorrectionType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CorrectionType_MetaData)) }; // 739106298
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_SpatialClipping_MetaData[] = {
		{ "Category", "SRDisplay|Rendering" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "If checked, contents will be clipped at front of SR Display." },
	};
#endif
	void Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_SpatialClipping_SetBit(void* Obj)
	{
		((ASRDisplayManager*)Obj)->SpatialClipping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_SpatialClipping = { "SpatialClipping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ASRDisplayManager), &Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_SpatialClipping_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_SpatialClipping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_SpatialClipping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_IsSRRenderingActive_MetaData[] = {
		{ "Category", "SRDisplay|Rendering" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "If checked, display in 2D on SR Display." },
	};
#endif
	void Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_IsSRRenderingActive_SetBit(void* Obj)
	{
		((ASRDisplayManager*)Obj)->IsSRRenderingActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_IsSRRenderingActive = { "IsSRRenderingActive", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ASRDisplayManager), &Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_IsSRRenderingActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_IsSRRenderingActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_IsSRRenderingActive_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_FarClip_MetaData[] = {
		{ "Category", "SRDisplay|Rendering" },
		{ "ClampMin", "0.0" },
		{ "DisplayName", "Far Clip (cm)" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "Far clipt distance (cm)." },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_FarClip = { "FarClip", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASRDisplayManager, FarClip), METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_FarClip_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_FarClip_MetaData)) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ScalingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ScalingMode_MetaData[] = {
		{ "Category", "SRDisplay|Rendering|Scaling Mode" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "Scaled mode or Original mode can be selected." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ScalingMode = { "ScalingMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASRDisplayManager, ScalingMode), Z_Construct_UEnum_SRDisplayModule_EScalingMode, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ScalingMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ScalingMode_MetaData)) }; // 3509688713
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_GizmoSize_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_GizmoSize_MetaData[] = {
		{ "Category", "SRDisplay|Rendering|Scaling Mode" },
		{ "EditCondition", "ScalingMode == EScalingMode::ORIGINAL_SIZE" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "size of SRDisplayManager gizmo can be selected." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_GizmoSize = { "GizmoSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASRDisplayManager, GizmoSize), Z_Construct_UEnum_SRDisplayModule_EGizmoSize, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_GizmoSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_GizmoSize_MetaData)) }; // 348790772
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_BoxColor_MetaData[] = {
		{ "Category", "SRDisplay|Appearance" },
		{ "Comment", "// Appearance\n" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "ToolTip", "Appearance" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_BoxColor = { "BoxColor", nullptr, (EPropertyFlags)0x0010020000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASRDisplayManager, BoxColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_BoxColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_BoxColor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_DisplayColor_MetaData[] = {
		{ "Category", "SRDisplay|Appearance" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_DisplayColor = { "DisplayColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASRDisplayManager, DisplayColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_DisplayColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_DisplayColor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_LineThickness_MetaData[] = {
		{ "Category", "SRDisplay|Appearance" },
		{ "ClampMax", "200.0" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayManager.h" },
		{ "UIMax", "200.0" },
		{ "UIMin", "1.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_LineThickness = { "LineThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ASRDisplayManager, LineThickness), METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_LineThickness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_LineThickness_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASRDisplayManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ShowCameraWindow,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CrosstalkCorrection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CorrectionType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_CorrectionType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_SpatialClipping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_IsSRRenderingActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_FarClip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ScalingMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_ScalingMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_GizmoSize_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_GizmoSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_BoxColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_DisplayColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASRDisplayManager_Statics::NewProp_LineThickness,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASRDisplayManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASRDisplayManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASRDisplayManager_Statics::ClassParams = {
		&ASRDisplayManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASRDisplayManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASRDisplayManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASRDisplayManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASRDisplayManager()
	{
		if (!Z_Registration_Info_UClass_ASRDisplayManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASRDisplayManager.OuterSingleton, Z_Construct_UClass_ASRDisplayManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASRDisplayManager.OuterSingleton;
	}
	template<> SRDISPLAYMODULE_API UClass* StaticClass<ASRDisplayManager>()
	{
		return ASRDisplayManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASRDisplayManager);
	ASRDisplayManager::~ASRDisplayManager() {}
	struct Z_CompiledInDeferFile_FID_release_srd_ue_plugin_ReleasePlugin_srd_ue_plugin_5_2_SRDisplayPlugin_HostProject_Plugins_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayManager_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_release_srd_ue_plugin_ReleasePlugin_srd_ue_plugin_5_2_SRDisplayPlugin_HostProject_Plugins_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayManager_h_Statics::EnumInfo[] = {
		{ ECrosstalkCorrectionType_StaticEnum, TEXT("ECrosstalkCorrectionType"), &Z_Registration_Info_UEnum_ECrosstalkCorrectionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 739106298U) },
		{ EScalingMode_StaticEnum, TEXT("EScalingMode"), &Z_Registration_Info_UEnum_EScalingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3509688713U) },
		{ EGizmoSize_StaticEnum, TEXT("EGizmoSize"), &Z_Registration_Info_UEnum_EGizmoSize, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 348790772U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_release_srd_ue_plugin_ReleasePlugin_srd_ue_plugin_5_2_SRDisplayPlugin_HostProject_Plugins_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASRDisplayManager, ASRDisplayManager::StaticClass, TEXT("ASRDisplayManager"), &Z_Registration_Info_UClass_ASRDisplayManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASRDisplayManager), 1460446864U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_release_srd_ue_plugin_ReleasePlugin_srd_ue_plugin_5_2_SRDisplayPlugin_HostProject_Plugins_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayManager_h_4040922531(TEXT("/Script/SRDisplayModule"),
		Z_CompiledInDeferFile_FID_release_srd_ue_plugin_ReleasePlugin_srd_ue_plugin_5_2_SRDisplayPlugin_HostProject_Plugins_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_release_srd_ue_plugin_ReleasePlugin_srd_ue_plugin_5_2_SRDisplayPlugin_HostProject_Plugins_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayManager_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_release_srd_ue_plugin_ReleasePlugin_srd_ue_plugin_5_2_SRDisplayPlugin_HostProject_Plugins_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayManager_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_release_srd_ue_plugin_ReleasePlugin_srd_ue_plugin_5_2_SRDisplayPlugin_HostProject_Plugins_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayManager_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
