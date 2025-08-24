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

	
protected:
	/* Combat Interface */
	virtual void Die() override;

private:
	
};
