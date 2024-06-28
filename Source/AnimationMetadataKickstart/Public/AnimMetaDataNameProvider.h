// Copyright 2024 Aaron Kemner, All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AnimMetaDataNameProvider.generated.h"

UINTERFACE(Blueprintable, BlueprintType)
class UAnimMetaDataNameProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ANIMATIONMETADATAKICKSTART_API IAnimMetaDataNameProvider
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category = "AnimMetaData")
	FName GetMetaDataName();
};
