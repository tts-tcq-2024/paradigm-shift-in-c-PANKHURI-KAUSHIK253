#include <stdio.h>
#define COOLING_THRESHOLD 30          // Temperature threshold for cooling mode (in °C)
#define HEATING_THRESHOLD 5           // Temperature threshold for heating mode (in °C)
#define HIGH_COOLING_THRESHOLD 40     // Temperature increase threshold for high cooling mode (in °C)
#define REFERENCE_TEMPERATURE 25

int batteryOperatingLimit(float temperature) 
{
  if(temperature > REFERENCE_TEMPERATURE) 
  {
    printf("High Cooling Mode: Temperature is very high (%.2f°C). Aggressive cooling required!\n", temperature);
  } 
  else if(temperature < REFERENCE_TEMPERATURE) 
  {
    printf("Heating Mode: Temperature is low (%.2f°C). Heating system activated.\n", temperature);
  } 
  else if(temperature == REFERENCE_TEMPERATURE) 
  {
    printf("No Action Needed\n");
  }
}

int main()
{
 batteryOperatingLimit(27);
}

