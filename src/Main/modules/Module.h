#ifndef modules_Module_H
#define modules_Module_H

#include <Arduino.h>  // Could just include WString.h, but including Arduino.h allows all modules to automatically get Arduino things like digitalWrite, delay, etc.

class Module {
   public:
	virtual const char* getName() const = 0;
	virtual void setup() = 0;
	virtual void loop() = 0;

   protected:
	~Module() {}
};

#endif