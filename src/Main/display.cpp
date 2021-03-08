#include "util.h"

#ifdef USE_DISPLAY

#if 1 == 0
// Arduino-Makefile automatically detects libraries based on #includes in source (.c or .cpp) files.
// It doesn't detect transient dependencies or libraries that don't have a header with the same name
// as the library folder, but we can trick it by putting fake #includes inside an #if guard that
// will never be true.

#include <Adafruit_BusIO.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#endif

#include "display.h"

OledDisplay *oled;
StatusManager *status;

void displaySetup() {
	SLOG("Initializing display");
	oled = new OledDisplay(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET_PIN);

	if (!oled->begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
		SLOG("Failed to init display");
		abort();
	}

	oled->setTextColor(WHITE);
	oled->setTextSize(1);
	oled->setCursor(0, 0);
	oled->setTextWrap(false);
	oled->display();
	status = new StatusManager(oled);
}

void displayLoop() {
	status->update();
}

void clearDisplay() {
	status->clear();
}

void putLine(uint32_t line, const char *format, ...) {
	va_list args1;
	va_start(args1, format);
	va_list args2;
	va_copy(args2, args1);

	// figure out needed length for message
	int messageLen = vsnprintf(NULL, 0, format, args1);
	va_end(args1);
	
	// create message buffer and print
	char message[messageLen + 1];
	vsnprintf(message, sizeof(message), format, args2);
	va_end(args2);
	
	status->put(line, message);
}

void putLine(uint32_t line, const __FlashStringHelper *format, ...) {
	// read the flash memory into a buffer
	const char *formatPtr = reinterpret_cast<const char *>(format);
	uint32_t formatLen = strlen_P(formatPtr);
	char formatBuf[formatLen + 1];

	for (uint32_t i = 0; i < formatLen; i++) {
		formatBuf[i] = pgm_read_byte(formatPtr + i);
	}

	formatBuf[formatLen] = 0;

	va_list args1, args2;
	va_start(args1, format);
	va_copy(args2, args1);

	// figure out needed length for message
	int messageLen = vsnprintf(NULL, 0, formatBuf, args1);
	va_end(args1);

	// create message buffer and print
	char message[messageLen + 1];
	vsprintf(message, formatBuf, args2);
	va_end(args2);

	status->put(line, message);
}

#endif