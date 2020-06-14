#pragma once

#include <BLEServer.h>
#include <functional>

class BLECharacteristicData : public BLECharacteristicCallbacks
{
public:
    BLECharacteristicData();

    BLECharacteristicData(BLECharacteristic* pCharacteristic);

    BLECharacteristic* GetCharacteristic();

    void SetReadHandler(std::function<std::string()> readHandler);

    void SetWriteHandler(std::function<void(const std::string&)> writeHandler);

    // Callback handlers
    void onRead(BLECharacteristic *pCharacteristic);
    void onWrite(BLECharacteristic *pCharacteristic);

private:
    BLECharacteristic* m_pCharacteristic;

    std::function<std::string()> m_readHandler;
    std::function<void(const std::string&)> m_writeHandler;
};
