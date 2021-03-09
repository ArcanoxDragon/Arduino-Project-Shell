#include "MainModule.h"

const char* MainModule::getName() const {
	return "Main";
}

void MainModule::setup() {
	// TODO: Put main setup code here
	delay(1000);
}

void MainModule::loop() {
    // TODO: Put main loop code here
	putLineF(0, "Test");
}