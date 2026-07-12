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
