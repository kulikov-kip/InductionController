#include "burst.h"

#include "globals.h"
#include "config.h"

static bool enabled = false;

// окно Burst

static uint16_t burstCounter = 0;

// аккумулятор алгоритма Брезенхема

static uint16_t accumulator = 0;

// количество периодов в окне

static uint16_t window = 100;

bool burstState()
{
    return enabled;
}

void burstEnable(bool state)
{
    enabled = state;

    if(!state)
        digitalWrite(PIN_BURST,LOW);
}

void burstInit()
{
    pinMode(PIN_BURST,OUTPUT);

    digitalWrite(PIN_BURST,LOW);

    // ---------- Timer1 ----------

    TCCR1A=0;
    TCCR1B=0;

    OCR1A=249;

    TCCR1B|=(1<<WGM12);

    TCCR1B|=(1<<CS11);
    TCCR1B|=(1<<CS10);

    TIMSK1|=(1<<OCIE1A);
}
