// Copyright 2024 Aaron Kemner, All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnimationMetadataLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONMETADATAKICKSTART_API UAnimationMetadataLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Get Asset AnimMetaData")
	static TArray<UAnimMetaData*> GetAssetAnimMetaData(const UAnimationAsset* Asset);
	
	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Get Asset AnimMetaData by Tag")
	static TArray<UAnimMetaData*> GetAssetAnimMetaDataByTag(const UAnimationAsset* Asset, const FGameplayTag TagToMatch);

	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Get Asset AnimMetaData by Name")
	static TArray<UAnimMetaData*> GetAssetAnimMetaDataByName(const UAnimationAsset* Asset, const FName NameToMatch);

	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Filter Assets by TagMetaData")
	static TArray<UAnimationAsset*> FilterAssetsByTagMetaData(const TArray<UAnimationAsset*>& Assets, const FGameplayTag TagToMatch);

	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Filter Assets by NameMetaData")
	static TArray<UAnimationAsset*> FilterAssetsByNameMetaData(const TArray<UAnimationAsset*>& Assets, const FName NameToMatch);
	
};
