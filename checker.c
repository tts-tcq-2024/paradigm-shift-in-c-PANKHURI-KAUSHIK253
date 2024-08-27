#include <stdio.h>
#include <assert.h>
 
int batteryOperatingLimit(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        printf("%s\n", message);
        return 1;
    }
    return 0;
}
 
int BatteryWithinLimit(float temperature, float soc, float chargeRate) {
    int TempRangeLimit = batteryOperatingLimit(temperature, 0, 45, "Temperature out of range!");
    int SocRangeLimit = batteryOperatingLimit(soc, 20, 80, "State of Charge out of range!");
    int ChargerateRangeLimit = batteryOperatingLimit(chargeRate, 0, 0.8, "Charge Rate out of range!");
 
    return !(isTempOutOfRange || isSocOutOfRange || isChargeRateOutOfRange);
}
 
int main() {
    assert(BatteryWithinLimit(25, 70, 0.7));
    assert(!BatteryWithinLimit(50, 85, 0));
}
