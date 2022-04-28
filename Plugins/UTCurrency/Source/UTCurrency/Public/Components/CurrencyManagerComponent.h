#pragma once

#include "Components/ActorComponent.h"
#include "CurrencyManagerComponent.generated.h"

/**
 * @brief Actor component responsible for tracking a specific currency
 */
UCLASS()
class UTCURRENCY_API UCurrencyManagerComponent final : public UActorComponent
{
	GENERATED_BODY()
	
public:
	/**
	 * @brief The unique ID associated with the currency being managed
	 */
	FString ID;

	/**
	 * @brief Get the current amount of currency
	 * @return The amount of currency
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Currency Manager")
	int GetAmount() const;

	/**
	 * @brief Add to the currency
	 * @param Amount The amount to add
	 * @return The new amount of currency
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Currency Manager")
	int Add(int Amount);

	/**
	 * @brief Remove from the currency
	 * @param Amount The amount to remove
	 * @return The new amount of currency
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Currency Manager")
	int Remove(int Amount);

	/**
	 * @brief Check if there is enough currency
	 * @param RequiredAmount The required amount of currency
	 * @return A boolean value indicating if there is enough currency
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Currency Manager")
	bool HaveEnough(int RequiredAmount) const;

private:
	/**
	 * @brief The amount of currency
	 */
	int Currency = 0;
};