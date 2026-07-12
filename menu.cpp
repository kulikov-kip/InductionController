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
