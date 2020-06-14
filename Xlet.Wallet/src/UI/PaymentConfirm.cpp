#include "UI/PaymentConfirm.h"
#include "Constants.h"
#include "Display/IDisplay.h"
#include "UI/Colors.h"

using namespace Xlet::Icons;

PaymentConfirm::PaymentConfirm(const std::string &amount)
    : m_amount(amount), m_redraw(true), m_offset(0)
{
}

void PaymentConfirm::Update(const std::list<InputEventType> &inputEvents)
{
    if (inputEvents.size() == 0)
    {
        return;
    }

    for (const auto &inputEvent : inputEvents)
    {
        switch (inputEvent)
        {
        case InputEventType::Up:
            m_onConfirm();

            break;

        case InputEventType::Select:
            m_onConfirm();

            break;

        case InputEventType::Down:
            m_offset -= 32;
            m_redraw = true;
            break;
        }
    }
}

void DrawIcons(IDisplay *display, int x, int y, const Xlet::Icons::Icon *icon)
{
    display->DrawBitmap(x, y, icon->GetWidth(), icon->GetHeight(), icon->GetImage());
}

void PaymentConfirm::OnConfirm(std::function<void()> onConfirm)
{
    m_onConfirm = onConfirm;
}

void PaymentConfirm::Draw(IDisplay *display)
{
    if (!m_redraw)
    {
        return;
    }

    display->FillScreen(Colors::Background);

    int screenWidth = display->GetWidth();
    int screenHeight = display->GetHeight();

    const int buttonMargin = 8;
    const int header = 16;
    const int footer = 32;

    int pos = screenHeight / 8;

    display->DrawString("Confirm Payment", screenWidth / 2, pos + header + m_offset, 4, Colors::Text, true);

    display->DrawString(m_amount.c_str(), screenWidth / 2, pos * 3 + header + m_offset, 6, Colors::ButtonHighlight, true);

    display->DrawString("XLM", screenWidth / 2, pos * 4 + header + m_offset, 4, Colors::Text, true);

    display->DrawString("GCCVPYFOHY7ZB7557JKENAX62LUA", screenWidth / 2, pos * 5 + header + m_offset, 1, Colors::ButtonHighlight, true);
    display->DrawString("PLMGIWNZJAFV2MITK6T32V37KEJU", screenWidth / 2, pos * 5 + header + m_offset + 16, 1, Colors::ButtonHighlight, true);

    // LCD display
    display->DrawString("1:45pm", buttonMargin, buttonMargin, 1, Colors::Text);

    DrawIcons(display, screenWidth - buttonMargin - m_iconBattery.GetWidth(), 3, &m_iconBattery);
    DrawIcons(display, screenWidth - buttonMargin - m_iconBluetooth.GetWidth() - m_iconBattery.GetWidth(), 3, &m_iconBluetooth);

    DrawIcons(display, 50, screenHeight - m_iconCross.GetWidth(), &m_iconCross);
    DrawIcons(display, (screenWidth / 2) - (m_iconMoneyButton.GetWidth() / 2), screenHeight - m_iconMoneyButton.GetHeight(), &m_iconMoneyButton);
    DrawIcons(display, screenWidth - 50 - m_iconDown.GetWidth(), screenHeight - m_iconDown.GetHeight(), &m_iconDown);

    display->DrawLine(0, screenHeight - footer, screenWidth, screenHeight - footer, Colors::Text);

    m_redraw = false;
}
