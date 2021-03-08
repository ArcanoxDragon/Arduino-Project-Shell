#ifndef modules_display_H
#define modules_display_H

#ifdef USE_DISPLAY

#include "StatusManager.h"
#include "oled.h"

void displaySetup();
void displayLoop();
void clearDisplay();
void putLine(uint32_t line, const char *format, ...) __attribute__((format(printf, 2, 3)));
void putLine(uint32_t line, const __FlashStringHelper *format, ...);

#else

// Dummy defines

#define displaySetup()
#define displayLoop()
#define clearDisplay()
#define putLine(line, format, ...)

#endif

#define putLineF(line, format, ...) putLine(line, F(format), ## __VA_ARGS__)

#endif