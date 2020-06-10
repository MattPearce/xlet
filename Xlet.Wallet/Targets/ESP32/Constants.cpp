#pragma once

#include "../../Constants.h"

/*
    This file defines device-specific parameters - add new ESP32 devices in here to support them
*/

// Only M5Stack supported at the moment
#define M5STACK

#ifdef M5STACK

namespace Constants
{
    namespace Display
    {
        const int Width = 320;
        const int Height = 240;
    }

    namespace Controls
    {
        const InterfaceStyle Interface = InterfaceStyle::ThreeButton;
    }
}

#endif

#ifdef M5STICK
namespace Constants
{
    namespace Display
    {
        const int Width = 80;
        const int Height = 160;
    }

    namespace Controls
    {
        const InterfaceStyle Interface = InterfaceStyle::SingleButton;
    }
}

#endif

#ifdef TTGO_WATCH_2020
namespace Constants
{
    namespace Display
    {
        const int Width = 240;
        const int Height = 240;
    }

    namespace Controls
    {
        const InterfaceStyle Interface = InterfaceStyle::Touch;
    }
}

#endif

#ifdef TTGO_WRISTBAND
namespace Constants
{
    namespace Display
    {
        const int Width = 80;
        const int Height = 160;
    }

    namespace Controls
    {
        const InterfaceStyle Interface = InterfaceStyle::SingleButton;
    }
}

#endif
