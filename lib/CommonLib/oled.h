#ifndef CommonLib_oled_H
#define CommonLib_oled_H


// These defines can be uncommented to use a non-default value (the values below are the defaults)

#ifndef OledDisplay
#include <Adafruit_SSD1306.h>
#define OledDisplay Adafruit_SSD1306
#endif

#ifndef OLED_I2C_ADDR
#define OLED_I2C_ADDR 0x3C
#endif

#ifndef OLED_RESET_PIN
#define OLED_RESET_PIN -1
#endif

#ifndef OLED_WIDTH
#define OLED_WIDTH 128
#endif

#ifndef OLED_HEIGHT
#define OLED_HEIGHT 64
#endif

#ifndef OLED_CHAR_WIDTH
#define OLED_CHAR_WIDTH 5
#endif

#ifndef OLED_CHAR_HEIGHT
#define OLED_CHAR_HEIGHT 8
#endif

#ifndef OLED_COLS
#define OLED_COLS 25
#endif

#ifndef OLED_ROWS
#define OLED_ROWS 8
#endif

#ifndef OLED_SCROLL_INTERVAL
#define OLED_SCROLL_INTERVAL 50
#endif

#endif