#pragma once

#include <Network/IBluetoothAdapter.h>
#include <unordered_map>
#include "BLECharacteristicData.h"
#include <memory>

class M5StackBluetoothAdapter : IBluetoothAdapter
{
public:
    void Initialise();

    void CreateService(const std::string& serviceUUID);

    void CreateCharacteristic(const std::string& serviceUUID, const std::string& characteristicUUID);

    void SetCharacteristic(const std::string& characteristicUUID, const std::string& value);

    void SetCharacteristicReadHandler(const std::string& characteristicUUID, std::function<std::string()> onRead);

    void SetCharacteristicWriteHandler(const std::string& characteristicUUID, std::function<void(const std::string&)> onWrite);

    void StartService(const std::string& serviceUUID);

    void StartAdvertising();

protected:
    BLEServer* m_pServer;

    std::unordered_map<std::string, BLEService*> m_services;
    std::unordered_map<std::string, std::shared_ptr<BLECharacteristicData>> m_characteristics;
};
