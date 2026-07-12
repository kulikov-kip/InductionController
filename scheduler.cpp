#include "scheduler.h"

#include "encoder.h"
#include "menu.h"
#include "display.h"
#include "temperature.h"
#include "current.h"
#include "burst.h"
#include "fan.h"
#include "protection.h"
#include "statistics.h"
#include "eepromManager.h"

Scheduler scheduler;

void schedulerInit()
{
    uint32_t now = millis();

    scheduler.t10 = now;
    scheduler.t20 = now;
    scheduler.t50 = now;
    scheduler.t100 = now;
    scheduler.t250 = now;
    scheduler.t500 = now;
    scheduler.t1000 = now;
}

void schedulerRun()
{
    uint32_t now = millis();

    //--------------------10 ms--------------------

    if (now - scheduler.t10 >= 10)
    {
        scheduler.t10 = now;

        encoderTask();
        burstTask();
    }

    //--------------------20 ms--------------------

    if (now - scheduler.t20 >= 20)
    {
        scheduler.t20 = now;

        menuTask();
    }

    //--------------------50 ms--------------------

    if (now - scheduler.t50 >= 50)
    {
        scheduler.t50 = now;

        temperatureTask();
        currentTask();
        fanTask();
        protectionTask();
    }

    //--------------------100 ms--------------------

    if (now - scheduler.t100 >= 100)
    {
        scheduler.t100 = now;

        displayTask();
    }

    //--------------------250 ms--------------------

    if (now - scheduler.t250 >= 250)
    {
        scheduler.t250 = now;

        statisticsTask();
    }

    //--------------------500 ms--------------------

    if (now - scheduler.t500 >= 500)
    {
        scheduler.t500 = now;

        // резерв
    }

    //--------------------1000 ms--------------------

    if (now - scheduler.t1000 >= 1000)
    {
        scheduler.t1000 = now;

        eepromTask();
    }
}
