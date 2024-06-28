// Copyright 2024 Aaron Kemner, All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimMetaDataNameProvider.h"
#include "Animation/AnimMetaData.h"
#include "AnimMetaData_Name.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, DisplayName = "Name Anim Meta Data")
class ANIMATIONMETADATAKICKSTART_API UAnimMetaData_Name : public UAnimMetaData, public IAnimMetaDataNameProvider
{
	GENERATED_BODY()
public:
	UAnimMetaData_Name()
		: Name(NAME_None)
	{};
	
	UPROPERTY(EditDefaultsOnly, Category = "AnimMetaData")
	FName Name;

	//~ Begin IAnimMetaDataNameProvider Interface
	virtual FName GetMetaDataName_Implementation() override
		{ return Name; }
	//~ End IAnimMetaDataNameProvider Interface
};
