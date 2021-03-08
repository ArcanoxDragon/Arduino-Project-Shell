#ifndef util_H
#define util_H

#include <WString.h>

// TODO: Uncomment the following line to enable serial logging; comment it to disable serial logging
// #define USE_SERIAL

// TODO: Uncomment the following line to enable OLED display; comment it to disable OLED display
// #define USE_DISPLAY

#define SERIAL_BAUD 115200

#ifdef USE_SERIAL
#define SLOG(msg) Serial.println(F(msg)); \
                  Serial.flush()
#else
#define SLOG(msg)
#endif

void error(const char *message);
void error(const __FlashStringHelper *message);
bool isInitialized();
void setInitialized(bool initialized);

#endif