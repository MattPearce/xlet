#pragma once

// Only one target included for now - as more targets are added they will be enabled/disabled in here through flags
#ifdef XLET_TARGET_M5STACK
    #include <M5StackTarget.h>
#endif

// Currently only Stellar is supported
#include <StellarCrypto.h>