#pragma once

#include <stdint.h>

namespace Xlet
{
    namespace Icons
    {
        class Icon
        {
        public:
            virtual ~Icon() {}

			virtual const uint16_t* GetImage() const;

			virtual int GetWidth() const = 0;

			virtual int GetHeight() const = 0;

        protected:
            Icon() {}

        };
    }
}
