#include "menu.h"
#include "display.h"
#include "encoder.h"
#include "config.h"

static bool active = false;

static uint8_t item = 0;
static bool editMode = false;

const char *menuItems[] =
{
    "Burst",
    "Current Limit",
    "Fan ON",
    "Fan OFF",
    "Max Temp",
    "Statistics",
    "Reset Energy",
    "Exit"
};

const uint8_t MENU_ITEMS =
sizeof(menuItems)/sizeof(menuItems[0]);

extern Settings settings;
extern Runtime runtime;

bool menuActive()
{
    return active;
}

void menuInit()
{
    active=false;
    item=0;
    editMode=false;
}

void menuEnter()
{
    active=true;
    item=0;
    editMode=false;
}

void menuExit()
{
    active=false;
}
static void drawMenu()
{
    displayClearBuffer();

    uint8_t first=item;

    if(first>4)
        first=item-4;

    for(uint8_t i=0;i<4;i++)
    {
        uint8_t index=first+i;

        if(index>=MENU_ITEMS)
            break;

        char line[21];

        if(index==item)
            snprintf(line,21,">%s",menuItems[index]);
        else
            snprintf(line,21," %s",menuItems[index]);

        switch(i)
        {
            case 0:
                strncpy((char*)lcdBuffer[0],line,20);
                break;

            case 1:
                strncpy((char*)lcdBuffer[1],line,20);
                break;

            case 2:
                strncpy((char*)lcdBuffer[2],line,20);
                break;

            case 3:
                strncpy((char*)lcdBuffer[3],line,20);
                break;
        }
    }

    displayUpdate();
}
