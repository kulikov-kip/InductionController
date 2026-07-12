#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

//======================
// Версия
//======================

#define FW_VERSION "1.0.0"

//======================
// Пины
//======================

constexpr uint8_t PIN_BURST      = 9;
constexpr uint8_t PIN_TEMP        = 3;
constexpr uint8_t PIN_FAN_RELAY   = 4;
constexpr uint8_t PIN_ALARM_RELAY = 5;

constexpr uint8_t PIN_ENC_A       = 6;
constexpr uint8_t PIN_ENC_B       = 7;
constexpr uint8_t PIN_ENC_KEY     = 8;

constexpr uint8_t PIN_CURRENT     = A0;

//======================
// LCD
//======================

constexpr uint8_t LCD_ROWS = 4;
constexpr uint8_t LCD_COLS = 20;

//======================
// Константы
//======================

constexpr float SUPPLY_VOLTAGE = 48.0f;

constexpr float POWER_MIN = 0.0f;
constexpr float POWER_MAX = 6.0f;

constexpr float POWER_STEP = 0.1f;
constexpr float POWER_FAST_STEP = 0.5f;

constexpr uint8_t BURST_MIN = 40;
constexpr uint8_t BURST_MAX = 80;
constexpr uint8_t BURST_DEFAULT = 50;

constexpr float FAN_ON_DEFAULT = 60.0f;
constexpr float FAN_OFF_DEFAULT = 55.0f;

constexpr float MAX_TEMP_DEFAULT = 70.0f;

constexpr float CURRENT_LIMIT_DEFAULT = 120.0f;

constexpr uint8_t EEPROM_MAGIC = 0x5A;

#endif
