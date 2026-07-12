#include "config.h"
#include "globals.h"

#include "scheduler.h"

#include "display.h"
#include "encoder.h"
#include "menu.h"
#include "burst.h"
#include "temperature.h"
#include "current.h"
#include "fan.h"
#include "protection.h"
#include "statistics.h"
#include "eepromManager.h"

void setup()
{
    displayInit();

    encoderInit();

    burstInit();

    temperatureInit();

    currentInit();

    fanInit();

    protectionInit();

    statisticsInit();

    eepromInit();

    schedulerInit();

    displayBoot();
}

void loop()
{
    schedulerRun();
}
