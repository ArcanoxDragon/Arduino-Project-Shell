#ifndef CommonLib_CommonLib_H
#define CommonLib_CommonLib_H

#include <Module.h>

#include "util.h"
#include "oled.h"
#include "display.h"

void commonSetup(uint8_t numModules, Module* const modules[]);
void commonLoop(uint8_t numModules, Module* const modules[]);

#endif