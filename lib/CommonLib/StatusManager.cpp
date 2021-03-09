#include "util.h"

#include <Arduino.h>
#include <assert.h>

#include "StatusManager.h"

// #region Public

StatusManager::StatusManager(OledDisplay *oled) {
	this->oled = oled;

	for (uint8_t line = 0; line < OLED_ROWS; line++) {
		this->messages[line] = (char *)malloc(LINE_BUFFER_SIZE * sizeof(char));

		if (this->messages[line] <= 0) {
#ifdef USE_SERIAL
			Serial.print(F("Failed to allocate memory for StatusManager (at line "));
			Serial.print(line);
			Serial.println(F(")"));
			Serial.flush();
#endif
			return;
		}

		for (uint8_t c = 0; c < LINE_BUFFER_SIZE; c++) {
			this->messages[line][c] = ' ';
		}
	}
}

StatusManager::~StatusManager() {
	for (uint8_t line = 0; line < OLED_ROWS; line++) {
		free(this->messages[line]);
		this->messages[line] = NULL;
	}
}

void StatusManager::update() {
	if (!this->messages) return;

	if (millis() >= this->scrollTimer) {
		this->scroll();
	}
}

void StatusManager::clear() {
	if (!this->messages) return;

	this->oled->clearDisplay();

	for (uint8_t line = 0; line < OLED_ROWS; line++) {
		this->put(line, "");
	}
}

void StatusManager::put(uint8_t line, const char *message) {
	this->messagePos[line] = 0;
	this->messageLen[line] = strlen(message);
	this->formatLine(line, message);
	this->write(line);
	this->oled->display();
}

// #endregion Public

// #region Private

void StatusManager::formatLine(uint8_t line, const char *message) {
	if (!this->messages) return;

	uint32_t messageLen = this->messageLen[line];
	char *dst = this->messages[line];

	if (messageLen > OLED_COLS) {
		// Pad 3 spaces onto the end of the message so that when it wraps, there is space between the start and end

		snprintf(dst, LINE_BUFFER_SIZE, "%s   ", message);
	} else {
		snprintf(dst, LINE_BUFFER_SIZE, "%s", message);
	}

	if (messageLen >= LINE_BUFFER_SIZE) {
		dst[LINE_BUFFER_SIZE - 1] = '\0';  // sprintf wouldn't have placed it; we'll truncate the last character
	}
}

void StatusManager::scroll() {
	if (!this->messages) return;

	for (uint8_t line = 0; line < OLED_ROWS; line++) {
		if (this->messageLen[line] > OLED_COLS) {
			this->messagePos[line]++;
			this->messagePos[line] %= this->messageLen[line];
			this->write(line);
		}
	}

	this->oled->display();
	this->scrollTimer = millis() + OLED_SCROLL_INTERVAL;
}

void StatusManager::write(uint8_t line) {
	if (!this->messages) return;

	assert(line < OLED_ROWS);

	uint8_t lineTop = OLED_CHAR_HEIGHT * line;

	// Clear the line and the print the text
	this->oled->fillRect(0, lineTop, OLED_WIDTH, OLED_CHAR_HEIGHT, BLACK);
	this->oled->setCursor(0, lineTop);
	this->printOffset(this->messages[line], this->messagePos[line]);
}

void StatusManager::printOffset(char *message, int16_t offset) {
	if (!message || !this->messages) return;

	uint32_t len = strlen(message);
	char buffer[OLED_COLS];

	for (uint32_t c = 0; c < OLED_COLS; c++) {
		if (c < len) {
			buffer[c] = message[(c + offset) % len];
		} else {
			buffer[c] = ' ';
		}
	}

	this->oled->print(buffer);
}

// #endregion Private