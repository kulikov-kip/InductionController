#include "encoder.h"
#include "config.h"

static uint8_t oldState;
static int8_t delta = 0;

static bool shortClickFlag = false;
static bool longClickFlag = false;

static bool buttonPressed = false;

static uint32_t pressTime = 0;
static uint32_t lastStepTime = 0;

static const int8_t encTable[16] =
{
     0,-1, 1, 0,
     1, 0, 0,-1,
    -1, 0, 0, 1,
     0, 1,-1, 0
};

void encoderInit()
{
    pinMode(PIN_ENC_A,INPUT_PULLUP);
    pinMode(PIN_ENC_B,INPUT_PULLUP);
    pinMode(PIN_ENC_SW,INPUT_PULLUP);

    oldState=(digitalRead(PIN_ENC_A)<<1)|digitalRead(PIN_ENC_B);
}

void encoderTask()
{
    //-------------------------------
    // энкодер
    //-------------------------------

    uint8_t state=(digitalRead(PIN_ENC_A)<<1)|digitalRead(PIN_ENC_B);

    if(state!=oldState)
    {
        uint8_t index=(oldState<<2)|state;

        int8_t step=encTable[index];

        if(step)
        {
            uint32_t now=millis();

            if(now-lastStepTime<80)
                step*=5;

            delta+=step;

            lastStepTime=now;
        }

        oldState=state;
    }

    //-------------------------------
    // кнопка
    //-------------------------------

    bool sw=!digitalRead(PIN_ENC_SW);

    if(sw && !buttonPressed)
    {
        buttonPressed=true;
        pressTime=millis();
    }

    if(!sw && buttonPressed)
    {
        buttonPressed=false;

        if(millis()-pressTime<1200)
            shortClickFlag=true;
    }

    if(buttonPressed)
    {
        if(millis()-pressTime>2000)
        {
            longClickFlag=true;
            buttonPressed=false;
        }
    }
}

int8_t encoderGetDelta()
{
    int8_t value=delta;
    delta=0;
    return value;
}

bool encoderShortClick()
{
    bool f=shortClickFlag;
    shortClickFlag=false;
    return f;
}

bool encoderLongClick()
{
    bool f=longClickFlag;
    longClickFlag=false;
    return f;
}
