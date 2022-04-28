#pragma once

#include "Components/CurrencyManagerComponent.h"
#include "GameFramework/Actor.h"
#include "CurrencyManager.generated.h"

/**
 * @brief An actor responsible for managing all the currency manager components
 */
UCLASS()
class UTCURRENCY_API ACurrencyManager : public AActor
{
	GENERATED_BODY()
	
public:
	
	/**
	 * @brief Create a new instance of the currency manager class
	 */
	ACurrencyManager();
	
	/**
	 * @brief Get a reference to the currency manager component responsible for managing the coins
	 * @return A reference coin currency manager
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Currency Manager")
	UCurrencyManagerComponent* GetCoinManager() const;

	/**
	 * @brief Get a reference to the currency manager component responsible for managing the gems
	 * @return A reference gem currency manager
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Currency Manager")
	UCurrencyManagerComponent* GetGemManager() const;
	
	/**
	 * @brief Add a custom currency manager component
	 * @param ID The unique ID associated with the currency manager component
	 * @return A reference to the new currency manager component
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Currency Manager")
	UCurrencyManagerComponent* AddManager(FString ID);
	
	/**
	 * @brief Get a reference to a custom currency manager component
	 * @param ID The unique ID associated with the currency manager component
	 * @return A reference to the custom currency manager component
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Currency Manager")
	UCurrencyManagerComponent* GetManager(FString ID);

private:	
	/**
	 * @brief A reference to the currency manager component responsible for managing the coins 
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCurrencyManagerComponent* CoinManager;

	/**
	 * @brief A reference to the currency manager component responsible for managing the gems 
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCurrencyManagerComponent* GemManager;
	
	/**
	 * @brief A map of all the custom currency manager components
	 */
	UPROPERTY() TMap<FString, UCurrencyManagerComponent*> CustomManagers;
};