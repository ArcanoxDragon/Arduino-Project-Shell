#ifndef config_H
#define config_H

// TODO: Uncomment the following line to enable serial logging; comment it to disable serial logging
// #define USE_SERIAL

// TODO: Uncomment the following line to enable OLED display; comment it to disable OLED display
#define USE_DISPLAY

// The following commented-out defines can be uncommented to use a non-default value (the values below are the defaults)

// #define SERIAL_BAUD 115200

#ifdef USE_DISPLAY
#include "config_oled.h"
#endif

#endif