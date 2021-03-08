#ifndef modules_MainModule_h
#define modules_MainModule_h

#include "Module.h"

class MainModule : public Module {
   public:
	virtual const char* getName() const;
	virtual void setup();
	virtual void loop();
};

#endif