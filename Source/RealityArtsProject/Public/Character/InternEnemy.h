// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "Character/InternCharacterBase.h"
#include "InternEnemy.generated.h"

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternEnemy : public AInternCharacterBase
{
	GENERATED_BODY()

public:

	/* Combat Interface */

	virtual void Die() override;
};
