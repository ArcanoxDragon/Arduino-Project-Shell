#ifndef CommonLib_util_H
#define CommonLib_util_H

#include <WString.h>

#ifndef SERIAL_BAUD
#define SERIAL_BAUD 115200
#endif

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

#define ARRAYLEN(array) sizeof(array) / sizeof(array[0])

#endif