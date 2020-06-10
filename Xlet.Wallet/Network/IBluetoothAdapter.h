#pragma once

class IBluetoothAdapter
{
public:
    virtual void Initialise() = 0;

    virtual void CreateService() = 0;

    virtual void CreateCharacteristic() = 0;

    virtual ~IBluetoothAdapter() {}

protected:
    IBluetoothAdapter() {}
};
