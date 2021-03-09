#include <Arduino.h>
#include <CommonLib.h>

// Module includes
#include "modules/MainModule.h"
// TODO: Include additional modules here

Module* const MODULES[] = {
    new MainModule(),
    // TODO: Construct additional modules here
};

void setup() {
	commonSetup(ARRAYLEN(MODULES), MODULES);
}

void loop() {
	commonLoop(ARRAYLEN(MODULES), MODULES);
}