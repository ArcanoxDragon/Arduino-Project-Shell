#include <stdio.h>
#include "util.h"
#include "display.h"

bool initialized = false;

void error(const char *message) {
#ifdef USE_SERIAL
	char errMessage[strlen(message) + 8];
	snprintf(errMessage, sizeof(errMessage), "Error: %s", message);
#endif
#ifdef USE_DISPLAY
	clearDisplay();
	putLine(6, F("ERROR:"));
	putLine(7, message);
#endif
	initialized = false;
}

bool isInitialized() {
	return initialized;
}

void setInitialized(bool i) {
	initialized = i;
}