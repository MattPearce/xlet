#pragma once

#include <string>

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
}
