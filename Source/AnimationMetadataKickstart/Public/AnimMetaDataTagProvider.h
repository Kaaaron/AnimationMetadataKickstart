// Copyright 2024 Aaron Kemner, All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AnimMetaDataTagProvider.generated.h"

UINTERFACE(Blueprintable, BlueprintType)
class UAnimMetaDataTagProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ANIMATIONMETADATAKICKSTART_API IAnimMetaDataTagProvider
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category = "AnimMetaData")
	FGameplayTag GetMetaDataTag();
};
