#ifndef BURST_H
#define BURST_H

#include <Arduino.h>

void burstInit();

void burstTask();

void burstEnable(bool state);

bool burstState();

#endif
