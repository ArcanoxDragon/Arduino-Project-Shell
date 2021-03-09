#ifndef CommonLib_Module_H
#define CommonLib_Module_H

// Could just include WString.h, but including Arduino.h allows all modules to automatically get Arduino things like digitalWrite, delay, etc.
// We can go ahead and include util.h and display.h too, so that modules automatically get that stuff as well
#include <Arduino.h>
#include "util.h"
#include "display.h"

class Module {
   public:
	virtual const char* getName() const = 0;
	virtual void setup() = 0;
	virtual void loop() = 0;

   protected:
	~Module() {}
};

#endif