#pragma once

#include <string>

enum InterfaceStyle
{
    SingleButton,
    ThreeButton,
    Touch
};

// Note: Externed constants should be defined in a target-specific constants file, e.g. /Targets/ESP32/Constants.cpp

namespace Constants
{
    namespace Bluetooth
    {
        namespace StellarPaymentService
        {
            const std::string ServiceUUID = "23d9e12d-9f60-45d3-b863-ac71d691eb02";

            namespace Characteristics
            {
                const std::string PaymentRequestUUID = "d201462b-0bc9-4f2e-88ce-751be9603925";
                const std::string PaymentResponseUUID = "ae1aef7f-f1fb-4fea-9c58-482e08dc65df";
            }
        }

        namespace PasswordManagerService
        {
            const std::string ServiceUUID = "0cb7490a-58fa-424e-858b-1e141d7260a9";

            namespace Characteristics
            {
                const std::string PasswordRequestUUID = "5b6f83ed-4f80-4ab9-80e4-cff7d272debe";
                const std::string PasswordResponseUUID = "87ba2a8b-e1a4-45a6-96ff-d848788b8be7";
            }
        }
    }
    
    namespace Display
    {
        const int Width = 320;
        const int Height = 240;
    }

    namespace Palette
    {
        const int Background = M5.Lcd.color565(0x16, 0x19, 0x25);
        const int Button = M5.Lcd.color565(0x3A, 0x44, 0x54);
        const int ButtonHighlight = M5.Lcd.color565(0x81, 0xD2, 0xC7);
        const int Text = M5.Lcd.color565(0xE0, 0xE0, 0xE0);
        const int TextMenu = M5.Lcd.color565(0x16, 0x19, 0x25);
        const int TextHighlight = M5.Lcd.color565(0xE8, 0xC5, 0x47);
    }

    namespace Size
    {
        const int Header = 16;
        const int Footer = 32;
        const int ButtonMargin = 8;
        const int ButtonsPerPage = 4;

        const int ScreenWidth = 320;
        const int ScreenHeight = 240;
    }

    namespace Controls
    {
        const InterfaceStyle Interface = InterfaceStyle::ThreeButton;
    }
}
