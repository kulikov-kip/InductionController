#ifndef EEPROM_MANAGER_H
#define EEPROM_MANAGER_H

#include <Arduino.h>

void eepromInit();
void eepromTask();

void settingsLoad();
void settingsSave();

#endif
