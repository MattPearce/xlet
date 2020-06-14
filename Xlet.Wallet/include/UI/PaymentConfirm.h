#pragma once

#include "IScreen.h"

#include <string>
#include <functional>
#include "Icons/Icons.h"

class PaymentConfirm : public IScreen
{
public:
    PaymentConfirm(const std::string& amount);

    void Update(const std::list<InputEventType>& inputEvents);

    void Draw(IDisplay* display);

    void OnConfirm(std::function<void()> onConfirm);

private:
    const std::string m_amount;

    bool m_redraw;

    int m_offset;

    std::function<void()> m_onConfirm;

    Xlet::Icons::Battery m_iconBattery;
    Xlet::Icons::Bluetooth m_iconBluetooth;
    Xlet::Icons::Cross m_iconCross;
    Xlet::Icons::MoneyButton m_iconMoneyButton;
    Xlet::Icons::Down m_iconDown;
};
