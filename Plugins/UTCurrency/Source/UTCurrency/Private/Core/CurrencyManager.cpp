#include "Core/CurrencyManager.h"
#include "Core/Log.h"

/**
 * @brief Create a new instance of the currency manager class
 */
ACurrencyManager::ACurrencyManager()
{
	CoinManager = CreateDefaultSubobject<UCurrencyManagerComponent>(TEXT("Coin Manager"));
	GemManager = CreateDefaultSubobject<UCurrencyManagerComponent>(TEXT("Gem Manager"));
}

/**
 * @brief Get a reference to the currency manager component responsible for managing the coins
 * @return A reference coin currency manager
 */
UCurrencyManagerComponent* ACurrencyManager::GetCoinManager() const
{
	return CoinManager;
}

/**
 * @brief Get a reference to the currency manager component responsible for managing the gems
 * @return A reference gem currency manager
 */
UCurrencyManagerComponent* ACurrencyManager::GetGemManager() const
{
	return GemManager;
}

/**
 * @brief Add a custom currency manager component
 * @param ID The unique ID associated with the currency manager component
 * @return A reference to the new currency manager component
 */
UCurrencyManagerComponent* ACurrencyManager::AddManager(FString ID)
{
	UCurrencyManagerComponent* ExistingManager = GetManager(ID);
	if (ExistingManager != nullptr)
	{
		ULog::Warning("CurrencyManager::AddManager",
			FString("Currency Manager already found with the same ID (").Append(ID).Append(")"));
		return ExistingManager;
	}

	UCurrencyManagerComponent* NewManager = NewObject<UCurrencyManagerComponent>();
	NewManager->ID = ID;
	CustomManagers.Add(ID, NewManager);

	ULog::Warning("CurrencyManager::AddManager",
		FString("Currency Manager added (").Append(ID).Append(")"));
	return NewManager;
}

/**
 * @brief Get a reference to a custom currency manager component
 * @param ID The unique ID associated with the currency manager component
 * @return A reference to the custom currency manager component
 */
UCurrencyManagerComponent* ACurrencyManager::GetManager(FString ID)
{
	if (CustomManagers.Contains(ID))
	{
		return CustomManagers[ID];
	}

	ULog::Warning("CurrencyManager::GetManager",
		FString("Currency Manager not registered (").Append(ID).Append(")"));
	return nullptr;
}