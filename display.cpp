#include "display.h"

hd44780_I2Cexp lcd;

static char lcdBuffer[4][21];
static char lcdOld[4][21];

void displayClearBuffer()
{
    for (uint8_t y = 0; y < 4; y++)
    {
        memset(lcdBuffer[y], ' ', 20);
        lcdBuffer[y][20] = 0;
    }
}

void displayInit()
{
    lcd.begin(20,4);

    lcd.clear();

    displayClearBuffer();

    for(uint8_t i=0;i<4;i++)
        lcdOld[i][0]=0;
}

void displayBoot()
{
    lcd.clear();

    lcd.setCursor(2,0);
    lcd.print("INDUCTION");

    lcd.setCursor(5,1);
    lcd.print("Controller");

    lcd.setCursor(7,2);
    lcd.print("v1.0");

    lcd.setCursor(2,3);
    lcd.print("Starting...");
}

void displayMain(
    float power,
    float current,
    float temperature,
    bool fan,
    bool heater,
    uint8_t burst,
    float energy)
{
    snprintf(
        lcdBuffer[0],
        21,
        "P:%4.1fkW I:%5.1fA",
        power,
        current);

    snprintf(
        lcdBuffer[1],
        21,
        "T:%4.1fC FAN:%s",
        temperature,
        fan ? "ON " : "OFF");

    snprintf(
        lcdBuffer[2],
        21,
        "Burst:%2dHz %s",
        burst,
        heater ? "RUN " : "STOP");

    snprintf(
        lcdBuffer[3],
        21,
        "E:%8.3fkWh",
        energy);
}

void displayFault(const char *text)
{
    displayClearBuffer();

    snprintf(lcdBuffer[0],21,"**** FAULT ****");
    snprintf(lcdBuffer[1],21,"%s",text);
    snprintf(lcdBuffer[2],21,"Heater OFF");
    snprintf(lcdBuffer[3],21,"Hold button...");
}

void displayUpdate()
{
    for(uint8_t row=0;row<4;row++)
    {
        if(strcmp(lcdBuffer[row],lcdOld[row])!=0)
        {
            lcd.setCursor(0,row);
            lcd.print(lcdBuffer[row]);

            uint8_t len=strlen(lcdBuffer[row]);

            while(len<20)
            {
                lcd.print(' ');
                len++;
            }

            strcpy(lcdOld[row],lcdBuffer[row]);
        }
    }
}
