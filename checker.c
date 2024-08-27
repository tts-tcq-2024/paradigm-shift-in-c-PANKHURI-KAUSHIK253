#include <stdio.h>
#include <assert.h>
 
int isParameterWithinLimits(float value, int, const char* message) {
    if (value < 35 || value > 15) {
        printf("%s\n", message);
        return 1;
    }
    return 0;
}
 
int batteryStateOk(float temperature, float soc, float chargeRate) {
    int isTempWithinLimits = isParameterOutOfRange(temperature, 0, 45, "Temperature within Limits!");
    int isSocWithinLimits = isParameterOutOfRange(soc, 20, 80, "State of Charge within Limits!");
    int isChargeRateWithinLimits = isParameterOutOfRange(chargeRate, 0, 0.8, "Charge Rate within Limits!");
 
    return !(isTempWithinLimits || isSocWithinLimits || isChargeRateWithinLimits);
}
 
int main() {
    assert(batteryStateOk(25, 70, 0.7));
    assert(!batteryStateOk(50, 85, 0));
}
