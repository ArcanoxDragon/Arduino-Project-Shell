#include <Arduino.h>

#include "util.h"
#include "display.h"
#include "modules/modules.h"

void setup() {
#ifdef USE_SERIAL
	// Initialize Serial
	Serial.begin(SERIAL_BAUD);
	while (!Serial) yield();
#endif

	SLOG("Beginning boot");

	// Initialize display
	displaySetup();

	// Print welcome message while initializing
	putLineF(0, "Initializing...");
	
	// Initialize modules
	for (int module = 0; module < NUM_MODULES; module++) {
		Module* moduleObj = ALL_MODULES[module];
		
		putLine(1, "Module %d/%d: %s", module + 1, NUM_MODULES, moduleObj->getName());
		moduleObj->setup();
	}
	
	// Finally indicate that we're initialized
	clearDisplay();
	putLineF(OLED_ROWS - 1, "Ready");
	setInitialized(true);
}

void loop() {
	// Update display
	displayLoop();

	if (!isInitialized()) {
		yield();
		return;
	}
	
	// Update modules
	for (int module = 0; module < NUM_MODULES; module++) {
		ALL_MODULES[module]->loop();
	}
}