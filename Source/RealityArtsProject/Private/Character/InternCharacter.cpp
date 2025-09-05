// Copyright baakidesu


#include "Character/InternCharacter.h"

AInternCharacter::AInternCharacter()
{
}

void AInternCharacter::Die() 
{
	Super::Die();
}

void AInternCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitializeAvaliableTags();
}

void AInternCharacter::InitializeAvaliableTags()
{

	BaseAbilitiesToGive.GenerateValueArray(AvailableGameplayTags);

	if (AvailableGameplayTags.Num() == 0 || IgnoredAttributes.Num() == 0) return;

	//TODO: ??
	const TSet<FGameplayTag> ToRemoveSet(IgnoredAttributes); 
	AvailableGameplayTags.RemoveAll([&](const FGameplayTag& Tag)
	{
		return ToRemoveSet.Contains(Tag);
	});
}


