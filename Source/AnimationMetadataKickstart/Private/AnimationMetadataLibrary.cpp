// Copyright 2024 Aaron Kemner, All Rights reserved.


#include "AnimationMetadataLibrary.h"

#include "AnimMetaDataNameProvider.h"
#include "AnimMetaDataTagProvider.h"
#include "Animation/AnimMetaData.h"

namespace AnimMetaDataUtils
{
	template <typename UInterfaceClass>
	void FilterAnimationAssetsByPredicate(const TArray<UAnimationAsset*>& Assets,
	                                      const TFunctionRef<bool (UAnimMetaData*)> Predicate,
	                                      TArray<UAnimationAsset*>& Result)
	{
		Result.Reset(Assets.Num());
		for (UAnimationAsset* Asset : Assets)
		{
			if(!Asset)
			{
				continue;
			}
			
			for (UAnimMetaData* MetaData : Asset->GetMetaData())
			{
				if (MetaData->Implements<UInterfaceClass>() && Predicate(MetaData))
				{
					Result.Add(Asset);
					break;
				}
			}
		}
		Result.Shrink();
	}
}

TArray<UAnimMetaData*> UAnimationMetadataLibrary::GetAssetAnimMetaData(const UAnimationAsset* Asset)
{
	if (!Asset)
	{
		return {};
	}

	return Asset->GetMetaData();
}

TArray<UAnimMetaData*> UAnimationMetadataLibrary::GetAssetAnimMetaDataByTag(const UAnimationAsset* Asset,
                                                                            const FGameplayTag TagToMatch)
{
	if (!Asset)
	{
		return {};
	}
	
	TArray<UAnimMetaData*> Result;
	Result.Reserve(Asset->GetMetaData().Num());
	
	for (UAnimMetaData* MetaData : Asset->GetMetaData())
	{
		if (MetaData->Implements<UAnimMetaDataTagProvider>() && TagToMatch == IAnimMetaDataTagProvider::Execute_GetMetaDataTag(MetaData))
		{
			Result.Add(MetaData);
		}
	}

	Result.Shrink();
	return Result;
}

TArray<UAnimMetaData*> UAnimationMetadataLibrary::GetAssetAnimMetaDataByName(const UAnimationAsset* Asset,
                                                                             const FName NameToMatch)
{
	if (!Asset)
	{
		return {};
	}
	
	TArray<UAnimMetaData*> Result;
	Result.Reserve(Asset->GetMetaData().Num());
	
	for (UAnimMetaData* MetaData : Asset->GetMetaData())
	{
		if (MetaData->Implements<UAnimMetaDataNameProvider>() && NameToMatch == IAnimMetaDataNameProvider::Execute_GetMetaDataName(MetaData))
		{
			Result.Add(MetaData);
		}
	}

	Result.Shrink();
	return Result;
}

TArray<UAnimationAsset*> UAnimationMetadataLibrary::FilterAssetsByTagMetaData(
	const TArray<UAnimationAsset*>& Assets, const FGameplayTag TagToMatch)
{
	TArray<UAnimationAsset*> Result;

	AnimMetaDataUtils::FilterAnimationAssetsByPredicate<UAnimMetaDataTagProvider>(
		Assets,
		[&TagToMatch](UAnimMetaData* MetaData)
		{
			return TagToMatch == IAnimMetaDataTagProvider::Execute_GetMetaDataTag(MetaData);
		},
		Result);

	return Result;
}

TArray<UAnimationAsset*> UAnimationMetadataLibrary::FilterAssetsByContainerTagMetaData(
	const TArray<UAnimationAsset*>& Assets, const FGameplayTagContainer TagsToMatch)
{
	TArray<UAnimationAsset*> Result;

	AnimMetaDataUtils::FilterAnimationAssetsByPredicate<UAnimMetaDataTagProvider>(
		Assets,
		[&TagsToMatch](UAnimMetaData* MetaData)
		{
			return TagsToMatch.HasTag(IAnimMetaDataTagProvider::Execute_GetMetaDataTag(MetaData));
		},
		Result);

	return Result;
}

TArray<UAnimationAsset*> UAnimationMetadataLibrary::FilterAssetsByNameMetaData(
	const TArray<UAnimationAsset*>& Assets, const FName NameToMatch)
{
	TArray<UAnimationAsset*> Result;

	AnimMetaDataUtils::FilterAnimationAssetsByPredicate<UAnimMetaDataNameProvider>(
		Assets,
		[&NameToMatch](UAnimMetaData* MetaData)
		{
			return NameToMatch == IAnimMetaDataNameProvider::Execute_GetMetaDataName(MetaData);
		},
		Result);

	return Result;
}
