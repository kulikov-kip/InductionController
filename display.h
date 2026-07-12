#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

extern hd44780_I2Cexp lcd;

// Инициализация дисплея
void displayInit();

// Начальная заставка
void displayBoot();

// Главный экран
void displayMain(
    float power,
    float current,
    float temperature,
    bool fan,
    bool heater,
    uint8_t burst,
    float energy);

// Экран аварии
void displayFault(const char *text);

// Очистка внутреннего буфера
void displayClearBuffer();

// Обновление только изменившихся строк
void displayUpdate();

#endif
