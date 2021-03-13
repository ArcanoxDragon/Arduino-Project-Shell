#include <CommonLib.h>

void commonSetup(uint8_t numModules, Module* const modules[]) {
#ifdef USE_SERIAL
	Serial.begin(SERIAL_BAUD);
	while (!Serial) yield();
#endif

	SLOG("Beginning boot");

	/* Initialize display */
	displaySetup();

	/* Print welcome message while initializing */
	putLineF(0, "Initializing...");

	/* Initialize modules */
	for (uint8_t m = 0; m < numModules; m++) {
		Module* module = modules[m];

		putLineF(1, "Module %d/%d: %s", m + 1, numModules, module->getName());
		module->setup();
		
		if (didError()) {
			// Halt execution if module setup threw an error
			putLineF(OLED_ROWS - 1, "Error");
			return;
		}
	}

	/* Finally indicate that we're initialized */
	clearScreen();
	putLineF(OLED_ROWS - 1, "Ready");
	setInitialized(true);
}

void commonLoop(uint8_t numModules, Module* const modules[]) {
	/* Update display */
	displayLoop();

	if (!isInitialized() || didError()) {
		yield();
		return;
	}

	/* Update modules */
	for (uint8_t m = 0; m < numModules; m++) {
		modules[m]->loop();
	}
}