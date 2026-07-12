#include "eepromManager.h"

#include <EEPROM.h>

#include "globals.h"
#include "config.h"

static uint32_t saveTimer = 0;
static bool changed = false;

void settingsLoad()
{
    EEPROM.get(0, ctrl.settings);

    if (ctrl.settings.magic != EEPROM_MAGIC)
    {
        ctrl.settings.magic = EEPROM_MAGIC;

        ctrl.settings.power = 3.0f;

        ctrl.settings.burst = BURST_DEFAULT;

        ctrl.settings.fanOn = FAN_ON_DEFAULT;

        ctrl.settings.fanOff = FAN_OFF_DEFAULT;

        ctrl.settings.maxTemp = MAX_TEMP_DEFAULT;

        ctrl.settings.currentLimit = CURRENT_LIMIT_DEFAULT;

        ctrl.settings.energy = 0.0f;

        EEPROM.put(0, ctrl.settings);
    }
}

void settingsSave()
{
    EEPROM.put(0, ctrl.settings);
}

void eepromInit()
{
    settingsLoad();
}

void eepromTask()
{
    static Settings oldSettings;

    if (memcmp(&oldSettings, &ctrl.settings, sizeof(Settings)) != 0)
    {
        memcpy(&oldSettings, &ctrl.settings, sizeof(Settings));
        changed = true;
        saveTimer = millis();
    }

    if (changed && (millis() - saveTimer > 5000))
    {
        settingsSave();
        changed = false;
    }
}
