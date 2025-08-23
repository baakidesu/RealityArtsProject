// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "Character/InternCharacterBase.h"
#include "Components/WidgetComponent.h"
#include "InternEnemy.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeath, class AInternEnemy*, Enemy);

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternEnemy : public AInternCharacterBase
{
	GENERATED_BODY()

public:
	
	AInternEnemy();
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnDeath OnDeath;
	
	/* Combat Interface */
	virtual void Die() override;
	/* Combat Interface */

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Combat")
	UWidgetComponent* HealthBarWidget;
	
};