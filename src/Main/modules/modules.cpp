#include "Module.h"
#include "modules.h"

#include "MainModule.h"
// TODO: Include additional modules here

Module* const ALL_MODULES[] = {
    new MainModule(),
    // TODO: Construct additional modules here
};

const int NUM_MODULES = sizeof(ALL_MODULES) / sizeof(ALL_MODULES[0]);