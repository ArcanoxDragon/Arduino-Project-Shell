#include <stdio.h>
#include "util.h"
#include "display.h"

bool initialized = false;
bool errorThrown = false;

void error(const char *message) {
#ifdef USE_SERIAL
	char errMessage[strlen(message) + 8];
	snprintf(errMessage, sizeof(errMessage), "Error: %s", message);
#endif
#ifdef USE_DISPLAY
	clearScreen();
	putLine(6, F("ERROR:"));
	putLine(7, message);
#endif
	errorThrown = true;
}

void error(const __FlashStringHelper *message) {
	// read the flash memory into a buffer
	const char *messagePtr = reinterpret_cast<const char *>(message);
	uint32_t messageLen = strlen_P(messagePtr);
	char messageBuf[messageLen + 1];

	for (uint32_t i = 0; i < messageLen; i++) {
		messageBuf[i] = pgm_read_byte(messagePtr + i);
	}

	messageBuf[messageLen] = 0;
	
	error(messageBuf);
}

bool didError() {
	return errorThrown;
}

bool isInitialized() {
	return initialized;
}

void setInitialized(bool i) {
	initialized = i;
}