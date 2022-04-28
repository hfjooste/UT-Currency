# Currency Plugin
A system that is used to easily manage different types of currency. It has built-in support for coins and gems. But can easily be used to manage multiple custom currencies

## Installation
1. Download the latest release from GitHub
2. Navigate to `C:\Program Files\Epic Games\UE_{VERSION}\Engine\Plugins\`
3. Create a `Marketplace` folder if needed
4. Extract the release and copy to the `Marketplace` folder
5. Open Unreal Engine
6. Click on `Edit > Plugins`
7. Enable the plugin under the `Installed > Unreal Toolbox` category
8. Restart Unreal Engine

## Currency Manager
Each map need to contain an instance of the `Currency Manager`. This can be done by creating a child instance of `Currency Manager` and placeing it anywhere in the current map. The `Currency Manager` contains 2 `Currency Manager Component` instances. This is used to manage the coins and gems. Custom managers can be added and retrieved by using the following functions:
1. `Add Manager` - Requires a custom ID (string). This will register a new `Currency  Manager Component`
2. `Get Manager` - Requires a custom ID (string). This will return the registered component or `nullptr` if a component with the specified ID is not registered

## Currency Manager Component
The `Currency Manager Component` is used to manage a specific currency. This can be achieved by using the following functions:
1. `Add` - Increase the amount of currency managed by the component
2. `Remove` - Decrease the amount of currency managed by the component
3. `Get Amount` - Return the amount of currency managed by the component
4. `Have Enough` - Returns a boolean value indicating if the amount of currency is equal to or greater than the specified amount