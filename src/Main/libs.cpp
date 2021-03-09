// Put includes in this file to implicitly add libaries needed by the sketch via Arduino.mk's auto lib detection
// Libraries are detected by regex, so the include does not actually need to be compiled (or even be valid)
// 
// Format is: #include <LibraryName.h>

#if 1 == 0

#include <Adafruit_BusIO.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <CommonLib.h>
#include <SPI.h>
#include <Wire.h>

#endif