#include "Components/CurrencyManagerComponent.h"
#include "Math/UnrealMathUtility.h"

/**
 * @brief Get the current amount of currency
 * @return The amount of currency
 */
int UCurrencyManagerComponent::GetAmount() const
{
	return Currency;
}

/**
 * @brief Add to the currency
 * @param Amount The amount to add
 * @return The new amount of currency
 */
int UCurrencyManagerComponent::Add(const int Amount)
{
	Currency = FMath::Max(Currency + Amount, 0);
	return Currency;
}

/**
 * @brief Remove from the currency
 * @param Amount The amount to remove
 * @return The new amount of currency
 */
int UCurrencyManagerComponent::Remove(const int Amount)
{
	Currency = FMath::Max(Currency - Amount, 0);
	return Currency;
}

/**
 * @brief Check if there is enough currency
 * @param RequiredAmount The required amount of currency
 * @return A boolean value indicating if there is enough currency
 */
bool UCurrencyManagerComponent::HaveEnough(const int RequiredAmount) const
{
	return Currency >= RequiredAmount;
}