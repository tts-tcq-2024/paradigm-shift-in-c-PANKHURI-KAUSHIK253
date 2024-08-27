#include <stdio.h>

#define COOLING_THRESHOLD 30          // Temperature threshold for cooling mode (in °C)
#define HEATING_THRESHOLD 5           // Temperature threshold for heating mode (in °C)
#define HIGH_COOLING_THRESHOLD 40     // Temperature increase threshold for high cooling mode (in °C)
#define REFERENCE_TEMPERATURE 25

// Function to categorize temperature into different modes
int categorizeTemperature(float temperature) {
    if (temperature > HIGH_COOLING_THRESHOLD) return 3; // High Cooling Mode
    if (temperature > COOLING_THRESHOLD) return 2;      // Cooling Mode
    if (temperature < HEATING_THRESHOLD) return 1;      // Heating Mode
    return 0;                                            // No Action Needed
}

void batteryOperatingLimit(float temperature) {
    int category = categorizeTemperature(temperature);

    switch (category) {
        case 3:
            printf("High Cooling Mode: Temperature is very high (%.2f°C). Aggressive cooling required!\n", temperature);
            break;
        case 2:
            printf("Cooling Mode: Temperature is high (%.2f°C). Cooling system activated.\n", temperature);
            break;
        case 1:
            printf("Heating Mode: Temperature is low (%.2f°C). Heating system activated.\n", temperature);
            break;
        case 0:
            printf("No Action Needed\n");
            break;
        default:
            printf("Unexpected category\n");
            break;
    }
}

int main() {
    batteryOperatingLimit(27);  // Test with a temperature value
    return 0;  // Indicate successful execution
}
