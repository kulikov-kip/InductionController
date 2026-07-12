#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

void encoderInit();
void encoderTask();

int8_t encoderGetDelta();

bool encoderShortClick();

bool encoderLongClick();

#endif
