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

	/** Get all AnimMetaData on the AnimationAsset. */
	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Get Asset AnimMetaData")
	static TArray<UAnimMetaData*> GetAssetAnimMetaData(const UAnimationAsset* Asset);

	/** Get all AnimMetaData on the Asset that matches the TagToMatch.
	 * Uses the result of GetMetaDataTag from the AnimMetaDataTagProvider Interface to check against the TagToMatch. */
	UFUNCTION(BlueprintCallable,  Category = "AnimMetaData", DisplayName = "Get Asset AnimMetaData by Tag", meta=(BlueprintThreadsafe))
	static TArray<UAnimMetaData*> GetAssetAnimMetaDataByTag(const UAnimationAsset* Asset, const FGameplayTag TagToMatch);

	/** Get all AnimMetaData on the Asset that matches the NameToMatch.
	 * Uses the result of GetMetaDataName from the AnimMetaDataNameProvider Interface to check against the NameToMatch. */
	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Get Asset AnimMetaData by Name", meta=(BlueprintThreadsafe))
	static TArray<UAnimMetaData*> GetAssetAnimMetaDataByName(const UAnimationAsset* Asset, const FName NameToMatch);

	/** Get all animation assets that have at least one AnimMetaData instance that matches the TagToMatch.
	 * Uses the result of GetMetaDataTag from the AnimMetaDataTagProvider Interface to check against the TagToMatch. */
	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Filter Assets by TagMetaData", meta=(BlueprintThreadsafe))
	static TArray<UAnimationAsset*> FilterAssetsByTagMetaData(const TArray<UAnimationAsset*>& Assets, const FGameplayTag TagToMatch);

	/** Get all animation assets that have at least one AnimMetaData instance that matches any of the TagsToMatch.
	 * Uses the result of GetMetaDataTag from the AnimMetaDataTagProvider Interface to check against the Tags in TagsToMatch. */
	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Filter Assets by TagMetaData using Container", meta=(BlueprintThreadsafe))
	static TArray<UAnimationAsset*> FilterAssetsByContainerTagMetaData(const TArray<UAnimationAsset*>& Assets, const FGameplayTagContainer TagsToMatch);

	/** Get all animation assets that have at least one AnimMetaData instance that matches the NameToMatch.
	 * Uses the result of GetMetaDataName from the AnimMetaDataNameProvider Interface to check against the NameToMatch. */
	UFUNCTION(BlueprintCallable, Category = "AnimMetaData", DisplayName = "Filter Assets by NameMetaData", meta=(BlueprintThreadsafe))
	static TArray<UAnimationAsset*> FilterAssetsByNameMetaData(const TArray<UAnimationAsset*>& Assets, const FName NameToMatch);
	
};
