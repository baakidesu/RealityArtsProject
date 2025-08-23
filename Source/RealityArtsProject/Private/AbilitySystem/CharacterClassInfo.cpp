// Copyright baakidesu


#include "AbilitySystem/CharacterClassInfo.h"

FCharacterClassDefaultnfo UCharacterClassInfo::GetClassDefaultsInfo(ECharacterClass CharacterClass)
{
	return CharacterClassInformation.FindChecked(CharacterClass);
}
