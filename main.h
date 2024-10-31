int main() 
{
    ParameterConfig temperatureConfig = {1, 0, 45, 0}; // Warning enabled, no tolerance for temperature
    ParameterConfig socConfig = {1, 20, 80, 4};       // Warning enabled, 5% tolerance for SOC
    ParameterConfig chargeRateConfig = {1, 0, 0.8, 0}; // Warning enabled, no tolerance for charge rate
   
    assert(batteryIsOk(25, 70, 0.7, temperatureConfig, socConfig, chargeRateConfig));
    assert(!batteryIsOk(50, 85, 0, temperatureConfig, socConfig, chargeRateConfig));
    return 0;
}
