#ifndef oled_H
#define oled_H

#include "Adafruit_SSD1306.h"

#define OledDisplay Adafruit_SSD1306

#define OLED_I2C_ADDR 0x3C
#define OLED_RESET_PIN -1
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_CHAR_WIDTH 5
#define OLED_CHAR_HEIGHT 8
#define OLED_COLS 25
#define OLED_ROWS 8
#define OLED_SCROLL_INTERVAL 50

#define assert_line(line) assert(line < OLED_ROWS);

#endif