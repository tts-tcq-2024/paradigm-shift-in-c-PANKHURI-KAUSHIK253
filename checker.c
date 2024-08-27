#include <stdio.h>

#define COOLING_THRESHOLD 30          // Temperature threshold for cooling mode (in °C)
#define HEATING_THRESHOLD 5           // Temperature threshold for heating mode (in °C)
#define HIGH_COOLING_THRESHOLD 40     // Temperature increase threshold for high cooling mode (in °C)
#define REFERENCE_TEMPERATURE 25

void batteryOperatingLimit(float temperature) 
{
    // Use the ternary operator to determine the appropriate message
    printf("%s\n",
        (temperature > HIGH_COOLING_THRESHOLD) ? 
            "High Cooling Mode: Temperature is very high. Aggressive cooling required!" :
        (temperature > COOLING_THRESHOLD) ? 
            "Cooling Mode: Temperature is high. Cooling system activated." :
        (temperature < HEATING_THRESHOLD) ? 
            "Heating Mode: Temperature is low. Heating system activated." :
            "No Action Needed"
    );
}

int main()
{
    batteryOperatingLimit(27);  // Test with a temperature value
    return 0;  // Indicate successful execution
}
