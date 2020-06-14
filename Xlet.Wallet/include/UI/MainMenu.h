#pragma once

#include "IScreen.h"

#include <string>
#include <memory>
#include "Icons/Icons.h"

struct MenuOption
{
    std::string Text;

    std::shared_ptr<Xlet::Icons::Icon> IconNormal;
    std::shared_ptr<Xlet::Icons::Icon> IconActive;
};

class MainMenu : public IScreen
{
public:
    MainMenu();

    void Update(const std::list<InputEventType>& inputEvents);

    void Draw(IDisplay* display);

    void UpdateTime(const std::string& time);

    void ShowQR();

private:
    std::list<MenuOption> m_options;
    Xlet::Icons::Battery m_iconBattery;
    Xlet::Icons::Bluetooth m_iconBluetooth;
    Xlet::Icons::Up m_iconUp;
    Xlet::Icons::Check m_iconCheck;
    Xlet::Icons::Down m_iconDown;

    std::string m_time = "1:45pm";

    int m_selected;

    bool m_redraw;
    bool m_fullRedraw;

    bool m_showQR;
};
