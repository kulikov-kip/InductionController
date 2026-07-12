#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>

struct Scheduler
{
    uint32_t t10;
    uint32_t t20;
    uint32_t t50;
    uint32_t t100;
    uint32_t t250;
    uint32_t t500;
    uint32_t t1000;
};

extern Scheduler scheduler;

void schedulerInit();
void schedulerRun();

#endif
