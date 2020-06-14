#include "Network/M5StackBluetoothAdapter.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

void M5StackBluetoothAdapter::Initialise()
{
    BLEDevice::init("Matt's Xlet Wallet");

    m_pServer = BLEDevice::createServer();
}

void M5StackBluetoothAdapter::CreateService(const std::string& serviceUUID)
{
    auto service = m_pServer->createService(serviceUUID.c_str());

    m_services[serviceUUID] = service;
}

void M5StackBluetoothAdapter::StartService(const std::string& serviceUUID)
{
    m_services[serviceUUID]->start();
}

void M5StackBluetoothAdapter::CreateCharacteristic(const std::string& serviceUUID, const std::string& characteristicUUID)
{
    auto characteristic = m_services[serviceUUID]->createCharacteristic(characteristicUUID.c_str(),
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE |
        BLECharacteristic::PROPERTY_NOTIFY |
        BLECharacteristic::PROPERTY_INDICATE);

    m_characteristics[characteristicUUID] = std::make_shared<BLECharacteristicData>(characteristic);

    characteristic->setCallbacks(m_characteristics[characteristicUUID].get());
}

void M5StackBluetoothAdapter::SetCharacteristic(const std::string& characteristicUUID, const std::string& value)
{
    m_characteristics[characteristicUUID]->GetCharacteristic()->setValue(value);
}

void M5StackBluetoothAdapter::SetCharacteristicReadHandler(const std::string &characteristicUUID, std::function<std::string()> onRead)
{
    m_characteristics[characteristicUUID]->SetReadHandler(onRead);
}

void M5StackBluetoothAdapter::SetCharacteristicWriteHandler(const std::string &characteristicUUID, std::function<void(const std::string &)> onWrite)
{
    m_characteristics[characteristicUUID]->SetWriteHandler(onWrite);
}

void M5StackBluetoothAdapter::StartAdvertising()
{
    m_pServer->startAdvertising();
}
