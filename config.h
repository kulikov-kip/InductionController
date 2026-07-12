#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

//======================================================
//                    VERSION
//======================================================

#define FW_VERSION "1.0"

//======================================================
//                     PINOUT
//======================================================

constexpr uint8_t PIN_BURST   = 9;

constexpr uint8_t PIN_TEMP    = 3;

constexpr uint8_t PIN_FAN     = 4;

constexpr uint8_t PIN_ALARM   = 5;

constexpr uint8_t PIN_ENC_A   = 6;

constexpr uint8_t PIN_ENC_B   = 7;

constexpr uint8_t PIN_ENC_SW  = 8;

constexpr uint8_t PIN_CURRENT = A0;

//======================================================
//                    LCD
//======================================================

constexpr uint8_t LCD_ROWS = 4;
constexpr uint8_t LCD_COLS = 20;

//======================================================
//                 CONSTANTS
//======================================================

constexpr float SUPPLY_VOLTAGE = 48.0;

constexpr float MAX_POWER = 6.0;
constexpr float MIN_POWER = 0.0;

constexpr float POWER_STEP = 0.1;

constexpr uint8_t BURST_MIN = 40;
constexpr uint8_t BURST_MAX = 80;

constexpr uint8_t BURST_DEFAULT = 50;

constexpr float CURRENT_LIMIT_DEFAULT = 120.0;

constexpr float FAN_ON_DEFAULT = 60.0;

constexpr float FAN_OFF_DEFAULT = 55.0;

constexpr float MAX_TEMP_DEFAULT = 70.0;

//======================================================
//                  EEPROM
//======================================================

constexpr uint8_t EEPROM_MAGIC = 0x5A;

//======================================================
//              SYSTEM STATE
//======================================================

enum class SystemState : uint8_t
{
    Boot,
    Ready,
    Run,
    Menu,
    Fault
};

//======================================================
//                ALARMS
//======================================================

enum class AlarmCode : uint8_t
{
    None,

    OverTemperature,

    OverCurrent,

    TempSensor,

    CurrentSensor
};

//======================================================
//                SETTINGS
//======================================================

struct Settings
{
    uint8_t magic;

    float targetPower;

    uint8_t burst;

    float currentLimit;

    float fanOn;

    float fanOff;

    float maxTemp;

    float energy;
};

//======================================================
//               RUNTIME
//======================================================

struct Runtime
{
    float current;

    float temperature;

    float power;

    float energy;

    float maxCurrent;

    float maxTemperature;

    uint32_t runtimeSeconds;

    bool heater;

    bool fan;

    AlarmCode alarm;
};

#endif
