#pragma once

#include <ICrypto.h>

class StellarCrypto : public ICrypto
{
public:
    std::vector<uint8_t> BuildTransaction(const std::string& destination, int amount, int decimalPlaces);
};
