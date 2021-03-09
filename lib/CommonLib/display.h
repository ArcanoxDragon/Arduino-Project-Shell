#ifndef CommonLib_display_H
#define CommonLib_display_H

#if defined(USE_DISPLAY) || defined(_DISPLAY_CPP)

#include <stdint.h>
#include <WString.h>

void displaySetup();
void displayLoop();
void clearScreen();
void putLine(uint32_t line, const char *format, ...) __attribute__((format(printf, 2, 3)));
void putLine(uint32_t line, const __FlashStringHelper *format, ...);

#else

// Dummy defines

#define displaySetup()
#define displayLoop()
#define clearScreen()
#define putLine(line, format, ...)

#endif

#define putLineF(line, format, ...) putLine(line, F(format), ## __VA_ARGS__)

#endif