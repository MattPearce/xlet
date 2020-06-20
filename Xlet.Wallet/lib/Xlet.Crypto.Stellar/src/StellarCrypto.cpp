#include "StellarCrypto.h"

#include <base32/base32.h>

#include "Stellar/Stellar-transaction.h"

enum VersionBytes
{
    ed25519PublicKey = 6 << 3,   // G
    ed25519SecretSeed = 18 << 3, // S
    preAuthTx = 19 << 3,         // T
    sha256Hash = 23 << 3         // X
};

stellar::uint256 GetED25519(const std::string &publicKey)
{
    auto decoded = base32_decode(publicKey);
    auto versionByte = decoded[0];
    auto payload = decoded.substr(0, decoded.length() - 2);
    auto data = decoded.substr(1);
    auto checksum = decoded.substr(decoded.length() - 2);

    auto expectedVersion = VersionBytes::ed25519PublicKey;

    if (versionByte != = expectedVersion)
    {
        throw new std::exception("Key not expected type");
    }

    /* WIP: Implement CRC16XMODEM library for checksum verification
    const expectedChecksum = calculateChecksum(payload);
    if (!verifyChecksum(expectedChecksum, checksum)) {
        throw new Error(`invalid checksum`);
    }
    */

    stellar::uint256 result;

    for (int i = 0; i < result.size() && i < data.length(); ++i)
    {
        result[i] = data[i];
    }

    return result;
}

std::vector<uint8_t> StellarCrypto::BuildTransaction(const std::string &destination, int amount, int decimalPlaces)
{
    stellar::TransactionEnvelope env(stellar::ENVELOPE_TYPE_TX_V0);

    stellar::PaymentOp payment;

    // Defaults to native asset type (XLM)
    payment.amount = 500;
    payment.destination.ed25519() = GetED25519("");

    stellar::Operation paymentOp;

    env.v0().tx.operations.push_back(paymentOp);

    // WIP: Signing
    // env.v0().signatures.push_back();


}
