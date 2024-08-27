#include <stdio.h>
#include <assert.h>

#define COOLING_THRESHOLD 30          // Temperature threshold for cooling mode (in °C)
#define HEATING_THRESHOLD 5           // Temperature threshold for heating mode (in °C)
#define HIGH_COOLING_THRESHOLD 40     // Temperature increase threshold for high cooling mode (in °C)
#define REFERENCE_TEMPERATURE 25

int batteryOperatingLimit(float temperature) 
{
  if(temperature > REFERENCE_TEMPERATURE) 
  {
    printf("High Cooling Mode: Temperature is very high (%.2f°C). Aggressive cooling required!\n", temperature);
    return 0;
  } 
  else if(temperature < REFERENCE_TEMPERATURE) 
  {
    printf("Heating Mode: Temperature is low (%.2f°C). Heating system activated.\n", temperature);
    return 0;
  } 
  else if(temperature == REFERENCE_TEMPERATURE) 
  {
    printf("No Action Needed\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryOperatingLimit(27));

}

