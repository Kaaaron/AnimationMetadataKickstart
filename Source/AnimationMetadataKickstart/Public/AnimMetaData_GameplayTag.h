// Copyright 2024 Aaron Kemner, All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimMetaDataNameProvider.h"
#include "AnimMetaDataTagProvider.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimMetaData.h"
#include "AnimMetaData_GameplayTag.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Gameplay Tag Anim Meta Data")
class ANIMATIONMETADATAKICKSTART_API UAnimMetaData_GameplayTag : public UAnimMetaData, public IAnimMetaDataTagProvider, public IAnimMetaDataNameProvider
{
	GENERATED_BODY()
	UAnimMetaData_GameplayTag()
		: Tag(FGameplayTag::EmptyTag)
	{};

	UPROPERTY(EditDefaultsOnly, Category = "AnimMetaData")
	FGameplayTag Tag;

	
	//~ Begin IAnimMetaDataTagProvider Interface
	virtual FGameplayTag GetMetaDataTag_Implementation() override
		{ return Tag; }
	//~ End IAnimMetaDataTagProvider Interface

	
	//~ Begin IAnimMetaDataNameProvider Interface
	virtual FName GetMetaDataName_Implementation() override
		{ return Tag.GetTagName(); }
	//~ End IAnimMetaDataNameProvider Interface
};
