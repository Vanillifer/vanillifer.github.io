#include "PlayerProgressionComponent.h"


UPlayerProgressionComponent::UPlayerProgressionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerProgressionComponent::AddSkillPoints(int32 Amount)
{
	if (Amount <= 0)
	{
		return;
	}

	UnspentSkillPoints += Amount;
}

int32 UPlayerProgressionComponent::GetUnspentSkillPoints() const
{
	return UnspentSkillPoints;
}

bool UPlayerProgressionComponent::CanAffordUpgrade(int32 Cost) const
{
	return Cost > 0 && UnspentSkillPoints >= Cost;
}




bool UPlayerProgressionComponent::TryPurchaseStrengthUpgrade(int32 CharacterIndex)
{
	if (!CanPurchaseStrengthUpgrade(CharacterIndex))
	{
		return false;
	}

	if (!ApplyStrengthUpgrade(CharacterIndex, StrengthUpgradeAmount))
	{
		return false;
	}

	UnspentSkillPoints -= StrengthUpgradeCost;
	return true;
}

bool UPlayerProgressionComponent::TryPurchaseSpecialUpgrade(int32 CharacterIndex)
{
	if (!CanPurchaseSpecialUpgrade(CharacterIndex))
	{
		return false;
	}

	if (!ApplySpecialUpgrade(CharacterIndex, SpecialUpgradeAmount))
	{
		return false;
	}

	UnspentSkillPoints -= SpecialUpgradeCost;
	return true;
}

bool UPlayerProgressionComponent::TryPurchaseConstitutionUpgrade(int32 CharacterIndex)
{
	if (!CanPurchaseConstitutionUpgrade(CharacterIndex))
	{
		return false;
	}

	if (!ApplyConstitutionUpgrade(CharacterIndex, ConstitutionUpgradeAmount))
	{
		return false;
	}

	UnspentSkillPoints -= ConstitutionUpgradeCost;
	return true;
}

bool UPlayerProgressionComponent::TryPurchaseIntellectUpgrade(int32 CharacterIndex)
{
	if (!CanPurchaseIntellectUpgrade(CharacterIndex))
	{
		return false;
	}

	if (!ApplyIntellectUpgrade(CharacterIndex, IntellectUpgradeAmount))
	{
		return false;
	}

	UnspentSkillPoints -= IntellectUpgradeCost;
	return true;
}

bool UPlayerProgressionComponent::TryPurchaseAgilityUpgrade(int32 CharacterIndex)
{
	if (!CanPurchaseAgilityUpgrade(CharacterIndex))
	{
		return false;
	}

	if (!ApplyAgilityUpgrade(CharacterIndex, AgilityUpgradeAmount))
	{
		return false;
	}

	UnspentSkillPoints -= AgilityUpgradeCost;
	return true;
}



bool UPlayerProgressionComponent::CanPurchaseStrengthUpgrade(int32 CharacterIndex) const
{
	const bool bValidCharacter = CharacterIndex == 0 || CharacterIndex == 1;
	const bool bAllowedCharacter = !bRestrictUpgradesByCharacter || CharacterIndex == 0;

	return bValidCharacter
		&& bAllowedCharacter
		&& StrengthUpgradeAmount > 0
		&& CanAffordUpgrade(StrengthUpgradeCost);
}

bool UPlayerProgressionComponent::CanPurchaseSpecialUpgrade(int32 CharacterIndex) const
{
	const bool bValidCharacter = CharacterIndex == 0 || CharacterIndex == 1;
	const bool bAllowedCharacter = !bRestrictUpgradesByCharacter || CharacterIndex == 1;

	return bValidCharacter
		&& bAllowedCharacter
		&& SpecialUpgradeAmount > 0
		&& CanAffordUpgrade(SpecialUpgradeCost);
}

bool UPlayerProgressionComponent::CanPurchaseConstitutionUpgrade(int32 CharacterIndex) const
{
	return (CharacterIndex == 0 || CharacterIndex == 1)
		&& ConstitutionUpgradeAmount > 0
		&& CanAffordUpgrade(ConstitutionUpgradeCost);
}

bool UPlayerProgressionComponent::CanPurchaseIntellectUpgrade(int32 CharacterIndex) const
{
	const bool bValidCharacter = CharacterIndex == 0 || CharacterIndex == 1;

	return bValidCharacter
		&& IntellectUpgradeAmount > 0
		&& CanAffordUpgrade(IntellectUpgradeCost);
}

bool UPlayerProgressionComponent::CanPurchaseAgilityUpgrade(int32 CharacterIndex) const
{
	const bool bValidCharacter = CharacterIndex == 0 || CharacterIndex == 1;

	return bValidCharacter
		&& AgilityUpgradeAmount > 0
		&& CanAffordUpgrade(AgilityUpgradeCost);
}



int32 UPlayerProgressionComponent::GetXPRequirementForNextLevel() const
{
	if (PlayerLevel >= MaxPlayerLevel)
	{
		return 0;
	}

	const double BaseXP = FMath::Max(BaseXPRequirement, 1);

	const double Multiplier = FMath::IsFinite(XPGrowthMultiplier)
		? FMath::Max(static_cast<double>(XPGrowthMultiplier), 1.0)
		: 1.0;

	const double RequiredXP = BaseXP * FMath::Pow(Multiplier,
		static_cast<double>(FMath::Max(PlayerLevel - 1, 0)));

	if (!FMath::IsFinite(RequiredXP) || RequiredXP >= MAX_int32)
	{
		return MAX_int32;
	}

	return FMath::Max(FMath::RoundToInt(RequiredXP), 1);
}

void UPlayerProgressionComponent::AddXP(int32 Amount)
{
	if (Amount <= 0 || PlayerLevel >= MaxPlayerLevel)
	{
		return;
	}


	//int64 is temp used so two big int32 can be added safely
	int64 AvaliableXP = static_cast<int64>(CurrentXP) + Amount;

	while (PlayerLevel < MaxPlayerLevel)
	{
		const int32 RequiredXP = GetXPRequirementForNextLevel();

		if (AvaliableXP < RequiredXP)
		{
			break;
		}

		AvaliableXP -= RequiredXP;
		++PlayerLevel;

		AddSkillPoints(2);
	}

	CurrentXP = PlayerLevel >= MaxPlayerLevel
		? 0
		: static_cast<int32>(AvaliableXP);
}

int32 UPlayerProgressionComponent::GetPlayerLevel() const
{
	return PlayerLevel;
}

int32 UPlayerProgressionComponent::GetCurrentXP() const
{
	return CurrentXP;
}
