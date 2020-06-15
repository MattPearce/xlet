#pragma once

#include <string>
#include <functional>

class IBluetoothAdapter
{
public:
    virtual void Initialise() = 0;

    virtual void CreateService(const std::string& serviceUUID) = 0;

    virtual void StartService(const std::string& serviceUUID) = 0;

    virtual void CreateCharacteristic(const std::string& serviceUUID, const std::string& characteristicUUID) = 0;

    virtual void SetCharacteristic(const std::string& characteristicUUID, std::string value) = 0;

    virtual void SetCharacteristicReadHandler(const std::string& characteristicUUID, std::function<std::string()> onRead) = 0;

    virtual void SetCharacteristicWriteHandler(const std::string& characteristicUUID, std::function<void(const std::string&)> onWrite) = 0;

    virtual void StartAdvertising() = 0;

    virtual ~IBluetoothAdapter() {}

protected:
    IBluetoothAdapter() {}
};
