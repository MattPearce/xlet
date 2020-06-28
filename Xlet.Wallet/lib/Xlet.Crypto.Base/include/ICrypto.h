#pragma once

#include <vector>
#include <string>
#include <stdint.h>

class ICrypto
{
public:
    virtual ~ICrypto() {};

    std::vector<uint8_t> BuildTransaction(const std::string& destination, int amount, int decimalPlaces);

protected:
    ICrypto() {};
};
