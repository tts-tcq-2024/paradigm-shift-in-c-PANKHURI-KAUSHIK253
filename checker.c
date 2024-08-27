#include <stdio.h>

#define COOLING_THRESHOLD 30          // Temperature threshold for cooling mode (in °C)
#define HEATING_THRESHOLD 5           // Temperature threshold for heating mode (in °C)
#define HIGH_COOLING_THRESHOLD 40     // Temperature increase threshold for high cooling mode (in °C)
#define REFERENCE_TEMPERATURE 25

void batteryOperatingLimit(float temperature) 
{
  if (temperature > HIGH_COOLING_THRESHOLD) 
  {
    printf("High Cooling Mode: Temperature is very high (%.2f°C). Aggressive cooling required!\n", temperature);
  } 
  else if (temperature > COOLING_THRESHOLD) 
  {
    printf("Cooling Mode: Temperature is high (%.2f°C). Cooling system activated.\n", temperature);
  } 
  else if (temperature < HEATING_THRESHOLD) 
  {
    printf("Heating Mode: Temperature is low (%.2f°C). Heating system activated.\n", temperature);
  } 
  else 
  {
    printf("No Action Needed\n");
  }
}

int main()
{
  batteryOperatingLimit(27);  // Test with a temperature value
  return 0;  // Indicate successful execution
}
