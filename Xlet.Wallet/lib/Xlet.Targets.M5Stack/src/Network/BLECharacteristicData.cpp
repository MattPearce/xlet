#include "Network/BLECharacteristicData.h"

BLECharacteristicData::BLECharacteristicData()
    : m_pCharacteristic(nullptr)
{
}

BLECharacteristicData::BLECharacteristicData(BLECharacteristic* pCharacteristic)
    : m_pCharacteristic(pCharacteristic)
{
}

BLECharacteristic* BLECharacteristicData::GetCharacteristic()
{
    return m_pCharacteristic;
}

void BLECharacteristicData::SetReadHandler(std::function<std::string()> readHandler)
{
    m_readHandler = readHandler;
}

void BLECharacteristicData::SetWriteHandler(std::function<void(const std::string &)> writeHandler)
{
    m_writeHandler = writeHandler;
}

void BLECharacteristicData::onRead(BLECharacteristic* pCharacteristic)
{
    if (m_readHandler)
    {
        auto result = m_readHandler();

        pCharacteristic->setValue(result);
    }
}

void BLECharacteristicData::onWrite(BLECharacteristic* pCharacteristic)
{
    if (m_writeHandler)
    {
        m_writeHandler(pCharacteristic->getValue());
    }
}
