// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "Character/InternCharacterBase.h"
#include "InternCharacter.generated.h"

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternCharacter : public AInternCharacterBase
{
	GENERATED_BODY()


public:
	AInternCharacter();

	UPROPERTY(BlueprintReadOnly)
	TArray<FGameplayTag> AvailableGameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | GAS")
	TArray<FGameplayTag> IgnoredAttributes;

	
protected:
	/* Combat Interface */
	virtual void Die() override;

	virtual void BeginPlay() override;

private:

	void InitializeAvaliableTags();
	
};
