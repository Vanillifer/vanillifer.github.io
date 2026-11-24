#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerProgressionComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_API UPlayerProgressionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPlayerProgressionComponent();

	UFUNCTION(BlueprintCallable, Category = "Progression")
	void AddSkillPoints(int32 Amount);

	UFUNCTION(BlueprintPure, Category = "Progression")
	int32 GetUnspentSkillPoints() const;

	UFUNCTION(BlueprintPure, Category = "Progression")
	bool CanAffordUpgrade(int32 Cost) const;
	//*
	//*
	//STRENGTH
	UFUNCTION(BlueprintCallable, Category  = "Progression|Upgrades")
	bool TryPurchaseStrengthUpgrade(int32 CharacterIndex);

	UFUNCTION(BlueprintPure, Category = "Progression|Upgrades")
	bool CanPurchaseStrengthUpgrade(int32 CharacterIndex) const;
	//*
	//*
	//SPECIAL
	UFUNCTION(BlueprintCallable, Category = "Progression|Upgrades")
	bool TryPurchaseSpecialUpgrade(int32 CharacterIndex);

	UFUNCTION(BlueprintPure, Category = "Progression|Upgrades")
	bool CanPurchaseSpecialUpgrade(int32 CharacterIndex) const;
	//*
	//*
	//CONSTITUTION
	UFUNCTION(BlueprintCallable, Category = "Progression|Upgrades")
	bool TryPurchaseConstitutionUpgrade(int32 CharacterIndex);

	UFUNCTION(BlueprintPure, Category = "Progression|Upgrades")
	bool CanPurchaseConstitutionUpgrade(int32 CharacterIndex) const;
	//*
	//*
	//INTELLECT
	UFUNCTION(BlueprintPure, Category = "Progression|Upgrades")
	bool CanPurchaseIntellectUpgrade(int32 CharacterIndex) const;

	UFUNCTION(BlueprintCallable, Category = "Progression|Upgrades")
	bool TryPurchaseIntellectUpgrade(int32 CharacterIndex);
	//*
	//*
	//AGILITY
	UFUNCTION(BlueprintPure, Category = "Progression|Upgrades")
	bool CanPurchaseAgilityUpgrade(int32 CharacterIndex) const;

	UFUNCTION(BlueprintCallable, Category = "Progression|Upgrades")
	bool TryPurchaseAgilityUpgrade(int32 CharacterIndex);
	//*
	//*
	//XP
	UFUNCTION(BlueprintCallable, Category = "Progression|XP")
	void AddXP(int32 Amount);

	UFUNCTION(BlueprintPure, Category = "Progression|XP")
	int32 GetXPRequirementForNextLevel() const;

	UFUNCTION(BlueprintPure, Category = "Progression|XP")
	int32 GetPlayerLevel() const;

	UFUNCTION(BlueprintPure, Category = "Progression|XP")
	int32 GetCurrentXP() const;



protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Progression")
	bool ApplyStrengthUpgrade(int32 CharacterIndex, int32 Amount);


	UFUNCTION(BlueprintImplementableEvent, Category = "Progression")
	bool ApplySpecialUpgrade(int32 CharacterIndex, int32 Amount);


	UFUNCTION(BlueprintImplementableEvent, Category = "Progression")
	bool ApplyConstitutionUpgrade(int32 CharacterIndex, int32 Amount);


	UFUNCTION(BlueprintImplementableEvent, Category = "Progression")
	bool ApplyAgilityUpgrade(int32 CharacterIndex, int32 Amount);


	UFUNCTION(BlueprintImplementableEvent, Category = "Progression")
	bool ApplyIntellectUpgrade(int32 CharacterIndex, int32 Amount);


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Progression", meta = (AllowPrivateAccess = "true"))
	int32 UnspentSkillPoints = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Progression|XP", meta = (AllowPrivateAccess = "true"))
	int32 PlayerLevel = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Progression|XP", meta = (AllowPrivateAccess = "true"))
	int32 CurrentXP = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades")
	bool bRestrictUpgradesByCharacter = false;
	//*
	//*
	//STRENGTH
	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Strength", meta = (ClampMin = "1"))
	int32 StrengthUpgradeCost = 1;

	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Strength", meta = (ClampMin = "0.1"))
	int32 StrengthUpgradeAmount = 1;
	//*
	//*
	//SPECIAL
	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Special", meta = (ClampMin = "1"))
	int32 SpecialUpgradeCost = 1;

	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Special", meta = (ClampMin = "0.1"))
	int32 SpecialUpgradeAmount = 1;
	//*
	//*
	//CONSTITUTION
	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Constitution", meta = (ClampMin = "1"))
	int32 ConstitutionUpgradeCost = 1;

	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Constitution", meta = (ClampMin = "0.1"))
	int32 ConstitutionUpgradeAmount = 1;
	//*
	//*
	//INTELLECT
	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Intellect", meta = (ClampMin = "1"))
	int32 IntellectUpgradeCost = 1;

	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Intellect", meta = (ClampMin = "1"))
	int32 IntellectUpgradeAmount = 1;
	//*
	//*
	//AGILITY
	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Agility", meta = (ClampMin = "1"))
	int32 AgilityUpgradeCost = 1;

	UPROPERTY(EditDefaultsOnly, Category = "Progression|Upgrades|Agility", meta = (ClampMin = "1"))
	int32 AgilityUpgradeAmount = 1;
	//*
	//*
	//XP
	UPROPERTY(EditDefaultsOnly, Category = "Progression|XP", meta = (ClampMin = "1"))
	int32 BaseXPRequirement = 100;

	UPROPERTY(EditDefaultsOnly, Category = "Progression|XP", meta = (ClampMin = "1.0"))
	float XPGrowthMultiplier = 1.1f;

	UPROPERTY(EditDefaultsOnly, Category = "Progression|XP", meta = (ClampMin = "1"))
	int32 MaxPlayerLevel = 50;
};
