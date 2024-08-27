// Define the baseline temperature (for demonstration purposes)
#define BASELINE_TEMPERATURE 25       // Example baseline temperature (in °C)

// Function prototypes
float getTemperature();
void manageThermal(float temperature);

int main() {
    while (1) {
        // Simulate getting the current temperature
        float temperature = getTemperature();
        
        // Manage thermal conditions based on the temperature
        manageThermal(temperature);
        
        // Simulated delay for the next check (could be replaced with actual timing code)
        for (volatile int i = 0; i < 1000000; ++i);  // Simple delay loop
    }
    return 0;
}

// Simulated function to get the current temperature (replace with actual sensor reading)
float getTemperature() {
    return 50.0;  // Example temperature value for demonstration
}

// Function to manage thermal conditions based on temperature
void manageThermal(float temperature) {
    static float previousTemperature = BASELINE_TEMPERATURE;

    if (temperature > COOLING_THRESHOLD) {
        if (temperature > (BASELINE_TEMPERATURE + HIGH_COOLING_THRESHOLD)) {
            printf("High Cooling Mode: Temperature is very high (%.2f°C). Aggressive cooling required!\n", temperature);
        } else {
            printf("Cooling Mode: Temperature is high (%.2f°C). Cooling system activated.\n", temperature);
        }
    } else if (temperature < HEATING_THRESHOLD) {
        printf("Heating Mode: Temperature is low (%.2f°C). Heating system activated.\n", temperature);
    } else {
        printf("Temperature is normal (%.2f°C). No special action required.\n", temperature);
    }
    
    // Update previous temperature for next comparison
    previousTemperature = temperature;
}
