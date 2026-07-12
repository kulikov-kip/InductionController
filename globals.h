#ifndef GLOBALS_H
#define GLOBALS_H

#include "config.h"

enum class SystemState : uint8_t
{
    BOOT,
    READY,
    RUN,
    MENU,
    FAULT
};

enum class AlarmCode : uint8_t
{
    NONE,
    OVER_TEMP,
    OVER_CURRENT,
    TEMP_SENSOR,
    CURRENT_SENSOR
};

struct Settings
{
    uint8_t magic;

    float targetPower;        // кВт

    uint8_t burstFrequency;   // 40...80 Гц

    float fanOnTemp;          // °C

    float fanOffTemp;         // °C

    float maxTemp;            // °C

    float currentLimit;       // А
};

struct Statistics
{
    float energykWh;

    uint32_t runtimeSeconds;

    float maxCurrent;

    float maxTemperature;

    uint32_t starts;
};

struct Runtime
{
    float current;

    float temperature;

    float power;

    bool heaterEnabled;

    bool fanEnabled;

    AlarmCode alarm;
};

struct Controller
{
    Settings settings;

    Statistics stats;

    Runtime runtime;

    SystemState state;
};

extern Controller ctrl;

#endif
