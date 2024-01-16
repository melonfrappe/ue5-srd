// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Classes/Blueprint/SRDisplayProjectSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSRDisplayProjectSettings() {}
// Cross Module References
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	SRDISPLAYMODULE_API UClass* Z_Construct_UClass_USRDisplayProjectSettings();
	SRDISPLAYMODULE_API UClass* Z_Construct_UClass_USRDisplayProjectSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SRDisplayModule();
// End Cross Module References
	void USRDisplayProjectSettings::StaticRegisterNativesUSRDisplayProjectSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USRDisplayProjectSettings);
	UClass* Z_Construct_UClass_USRDisplayProjectSettings_NoRegister()
	{
		return USRDisplayProjectSettings::StaticClass();
	}
	struct Z_Construct_UClass_USRDisplayProjectSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RunWithoutSRDisplayMode_MetaData[];
#endif
		static void NewProp_RunWithoutSRDisplayMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_RunWithoutSRDisplayMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USRDisplayProjectSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_SRDisplayModule,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayProjectSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Blueprint/SRDisplayProjectSettings.h" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayProjectSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USRDisplayProjectSettings_Statics::NewProp_RunWithoutSRDisplayMode_MetaData[] = {
		{ "Category", "SRDisplay" },
		{ "ModuleRelativePath", "Classes/Blueprint/SRDisplayProjectSettings.h" },
	};
#endif
	void Z_Construct_UClass_USRDisplayProjectSettings_Statics::NewProp_RunWithoutSRDisplayMode_SetBit(void* Obj)
	{
		((USRDisplayProjectSettings*)Obj)->RunWithoutSRDisplayMode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USRDisplayProjectSettings_Statics::NewProp_RunWithoutSRDisplayMode = { "RunWithoutSRDisplayMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USRDisplayProjectSettings), &Z_Construct_UClass_USRDisplayProjectSettings_Statics::NewProp_RunWithoutSRDisplayMode_SetBit, METADATA_PARAMS(Z_Construct_UClass_USRDisplayProjectSettings_Statics::NewProp_RunWithoutSRDisplayMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayProjectSettings_Statics::NewProp_RunWithoutSRDisplayMode_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USRDisplayProjectSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USRDisplayProjectSettings_Statics::NewProp_RunWithoutSRDisplayMode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USRDisplayProjectSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USRDisplayProjectSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USRDisplayProjectSettings_Statics::ClassParams = {
		&USRDisplayProjectSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USRDisplayProjectSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayProjectSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_USRDisplayProjectSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USRDisplayProjectSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USRDisplayProjectSettings()
	{
		if (!Z_Registration_Info_UClass_USRDisplayProjectSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USRDisplayProjectSettings.OuterSingleton, Z_Construct_UClass_USRDisplayProjectSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USRDisplayProjectSettings.OuterSingleton;
	}
	template<> SRDISPLAYMODULE_API UClass* StaticClass<USRDisplayProjectSettings>()
	{
		return USRDisplayProjectSettings::StaticClass();
	}
	USRDisplayProjectSettings::USRDisplayProjectSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USRDisplayProjectSettings);
	USRDisplayProjectSettings::~USRDisplayProjectSettings() {}
	struct Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_2_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayProjectSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_2_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayProjectSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USRDisplayProjectSettings, USRDisplayProjectSettings::StaticClass, TEXT("USRDisplayProjectSettings"), &Z_Registration_Info_UClass_USRDisplayProjectSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USRDisplayProjectSettings), 2774211095U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_2_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayProjectSettings_h_2517526230(TEXT("/Script/SRDisplayModule"),
		Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_2_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayProjectSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ue5_srd_Plugins_srd_ue_plugin_5_2_SRDisplayPlugin_Source_SRDisplayModule_Classes_Blueprint_SRDisplayProjectSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
