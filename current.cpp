#include "current.h"

#include "globals.h"
#include "config.h"

static float filteredCurrent = 0.0f;

//------------------------------------
// коэффициенты ACS758
//------------------------------------

constexpr float ADC_REF = 5.0f;

constexpr float ADC_MAX = 1023.0f;

// 150U = 13.3mV/A

constexpr float SENSOR_SENS = 0.0133f;

// смещение датчика

static float zeroOffset = 512.0f;

// коэффициент фильтра

constexpr float FILTER = 0.08f;

void currentInit()
{
    pinMode(PIN_CURRENT, INPUT);

    //--------------------------------
    // усредняем ноль
    //--------------------------------

    uint32_t sum = 0;

    for (uint8_t i = 0; i < 64; i++)
    {
        sum += analogRead(PIN_CURRENT);

        delay(2);
    }

    zeroOffset = sum / 64.0f;
}
static float readCurrent()
{
    uint16_t adc = analogRead(PIN_CURRENT);

    float voltage =
        ((float)adc - zeroOffset) *
        ADC_REF /
        ADC_MAX;

    float current =
        voltage /
        SENSOR_SENS;

    filteredCurrent +=
        FILTER *
        (current - filteredCurrent);

    return filteredCurrent;
}
void currentTask()
{

    ctrl.runtime.current = readCurrent();

    ctrl.runtime.power =
        ctrl.runtime.current *
        SUPPLY_VOLTAGE;

    if (ctrl.runtime.current >
        ctrl.stats.maxCurrent)
    {
        ctrl.stats.maxCurrent =
            ctrl.runtime.current;
    }

}
float currentGet()
{
    return ctrl.runtime.current;
}

float powerGet()
{
    return ctrl.runtime.power;
}
