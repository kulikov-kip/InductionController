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
    float power;

    uint8_t burst;

    float fanOn;

    float fanOff;

    float maxTemp;

    float currentLimit;

    float energy;

    uint8_t magic;
};

struct Runtime
{
    float current;

    float temperature;

    float power;

    float maxCurrent;

    float maxTemperature;

    uint32_t runtimeSeconds;

    bool heater;

    bool fan;

    AlarmCode alarm;
};

struct Controller
{
    Settings settings;

    Runtime runtime;

    SystemState state;
};

extern Controller ctrl;

#endif
