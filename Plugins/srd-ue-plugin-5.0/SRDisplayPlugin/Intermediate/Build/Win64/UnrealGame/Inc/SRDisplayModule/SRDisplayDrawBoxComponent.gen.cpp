// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SRDisplayModule/Classes/Blueprint/SRDisplayDrawBoxComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSRDisplayDrawBoxComponent() {}
// Cross Module References
	SRDISPLAYMODULE_API UClass* Z_Construct_UClass_USRDisplayDrawBoxComponent_NoRegister();
	SRDISPLAYMODULE_API UClass* Z_Construct_UClass_USRDisplayDrawBoxComponent();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent();
	UPackage* Z_Construct_UPackage__Script_SRDisplayModule();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
// End Cross Module References
	void USRDisplayDrawBoxComponent::StaticRegisterNativesUSRDisplayDrawBoxComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USRDisplayDrawBoxComponent);
	UClass* Z_Construct_UClass_USRDisplayDrawBoxComponent_NoRegister()
	{
		return USRDisplayDrawBoxComponent::StaticClass();
	}
	struct Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetScale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayWidth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DisplayWidth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DisplayHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimitiveComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SRDisplayModule,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object Mobility VirtualTexture Trigger" },
		{ "IncludePath", "Blueprint/SRDisplayDrawBoxComponent.h" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayDrawBoxComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_BoxColor_MetaData[] = {
		{ "Category", "DrawBoxComponent" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayDrawBoxComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_BoxColor = { "BoxColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USRDisplayDrawBoxComponent, BoxColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_BoxColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_BoxColor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayColor_MetaData[] = {
		{ "Category", "DrawBoxComponent" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayDrawBoxComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayColor = { "DisplayColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USRDisplayDrawBoxComponent, DisplayColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayColor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_LineThickness_MetaData[] = {
		{ "Category", "DrawBoxComponent" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayDrawBoxComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_LineThickness = { "LineThickness", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USRDisplayDrawBoxComponent, LineThickness), METADATA_PARAMS(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_LineThickness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_LineThickness_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_TargetScale_MetaData[] = {
		{ "Category", "DrawBoxComponent" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayDrawBoxComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_TargetScale = { "TargetScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USRDisplayDrawBoxComponent, TargetScale), METADATA_PARAMS(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_TargetScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_TargetScale_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayWidth_MetaData[] = {
		{ "Category", "DrawBoxComponent" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayDrawBoxComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayWidth = { "DisplayWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USRDisplayDrawBoxComponent, DisplayWidth), METADATA_PARAMS(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayWidth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayWidth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayHeight_MetaData[] = {
		{ "Category", "DrawBoxComponent" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayDrawBoxComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayHeight = { "DisplayHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USRDisplayDrawBoxComponent, DisplayHeight), METADATA_PARAMS(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayHeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayHeight_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_BoxColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_LineThickness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_TargetScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::NewProp_DisplayHeight,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USRDisplayDrawBoxComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::ClassParams = {
		&USRDisplayDrawBoxComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::PropPointers),
		0,
		0x00A830A4u,
		METADATA_PARAMS(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USRDisplayDrawBoxComponent()
	{
		if (!Z_Registration_Info_UClass_USRDisplayDrawBoxComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USRDisplayDrawBoxComponent.OuterSingleton, Z_Construct_UClass_USRDisplayDrawBoxComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USRDisplayDrawBoxComponent.OuterSingleton;
	}
	template<> SRDISPLAYMODULE_API UClass* StaticClass<USRDisplayDrawBoxComponent>()
	{
		return USRDisplayDrawBoxComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USRDisplayDrawBoxComponent);
	struct Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_0_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayDrawBoxComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_0_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayDrawBoxComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USRDisplayDrawBoxComponent, USRDisplayDrawBoxComponent::StaticClass, TEXT("USRDisplayDrawBoxComponent"), &Z_Registration_Info_UClass_USRDisplayDrawBoxComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USRDisplayDrawBoxComponent), 2528449522U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_0_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayDrawBoxComponent_h_664005099(TEXT("/Script/SRDisplayModule"),
		Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_0_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayDrawBoxComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_0_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayDrawBoxComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
