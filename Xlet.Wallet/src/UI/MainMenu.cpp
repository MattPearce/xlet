#include "UI/MainMenu.h"
#include "Constants.h"
#include "Display/IDisplay.h"
#include "UI/Colors.h"

using namespace Xlet::Icons;

MainMenu::MainMenu()
    : m_selected(0), m_redraw(true), m_fullRedraw(true), m_showQR(false)
{
  m_options = std::list<MenuOption>{
      MenuOption{
          "Pay", std::make_shared<Money>(), std::make_shared<MoneyActive>()},
      MenuOption{
          "Receive", std::make_shared<QR>(), std::make_shared<QRActive>()},
      MenuOption{
          "History", std::make_shared<Receipt>(), std::make_shared<ReceiptActive>()},
      MenuOption{
          "Settings", std::make_shared<Cog>(), std::make_shared<CogActive>()}};
}

void MainMenu::Update(const std::list<InputEventType> &inputEvents)
{
  if (inputEvents.size() == 0)
  {
    return;
  }

  m_redraw = true;

  for (const auto &inputEvent : inputEvents)
  {
    switch (inputEvent)
    {
    case InputEventType::Up:
      --m_selected;

      if (m_selected < 0)
      {
        m_selected = m_options.size() - 1;
      }

      break;

    case InputEventType::Select:
      if (m_selected == 1)
      {
        m_showQR = true;
      }
      break;

    case InputEventType::Down:
      ++m_selected;

      if (m_selected > 3)
      {
        m_selected = 0;
      }

      break;
    }
  }
}

void MainMenu::UpdateTime(const std::string& time)
{
  m_time = time;
  m_redraw = true;
  m_fullRedraw = true;
}

void MainMenu::ShowQR()
{
  m_showQR = true;
  m_redraw = true;
  m_fullRedraw = true;
}

void DrawIcon(IDisplay *display, int x, int y, const Xlet::Icons::Icon *icon)
{
  display->DrawBitmap(x, y, icon->GetWidth(), icon->GetHeight(), icon->GetImage());
}

void MainMenu::Draw(IDisplay *display)
{
  if (!m_redraw)
  {
    return;
  }

  if (m_fullRedraw)
  {
    display->FillScreen(Colors::Background);
  }

  if (m_showQR)
  {
    display->FillScreen(Colors::Background);
  }
  else
  {
    int screenWidth = display->GetWidth();
    int screenHeight = display->GetHeight();

    const int buttonMargin = 8;
    const int header = 16;
    const int footer = 32;
    const int buttonsPerPage = 4;

    const int buttonHeight = ((screenHeight - header - footer) - ((buttonsPerPage + 1) * buttonMargin)) / buttonsPerPage;

    int i = 0;

    for (const auto &option : m_options)
    {
      int y = header + (buttonMargin * (i + 1)) + buttonHeight * i;
      int w = screenWidth - (buttonMargin * 2);

      if (i == m_selected)
      {
        display->FillRoundRect(buttonMargin, y, w, buttonHeight, 5, Colors::ButtonHighlight);
        display->DrawRoundRect(buttonMargin, y, w, buttonHeight, 5, Colors::Text);
        DrawIcon(display, buttonMargin + 3, y + 3, option.IconActive.get());
      }
      else
      {
        display->FillRoundRect(buttonMargin, y, w, buttonHeight, 5, Colors::Button);
        DrawIcon(display, buttonMargin + 3, y + 3, option.IconNormal.get());
      }

      display->DrawString(option.Text.c_str(), buttonMargin + 38, y + 9, 4, Colors::TextMenu);

      ++i;
    }

    // LCD display
    display->DrawString(m_time.c_str(), buttonMargin, buttonMargin, 1, Colors::Text);

    DrawIcon(display, screenWidth - buttonMargin - m_iconBattery.GetWidth(), 3, &m_iconBattery);
    DrawIcon(display, screenWidth - buttonMargin - m_iconBluetooth.GetWidth() - m_iconBattery.GetWidth(), 3, &m_iconBluetooth);

    DrawIcon(display, 50, screenHeight - m_iconUp.GetWidth(), &m_iconUp);
    DrawIcon(display, (screenWidth / 2) - (m_iconCheck.GetWidth() / 2), screenHeight - m_iconCheck.GetHeight(), &m_iconCheck);
    DrawIcon(display, screenWidth - 50 - m_iconDown.GetWidth(), screenHeight - m_iconDown.GetHeight(), &m_iconDown);

    display->DrawLine(0, screenHeight - footer, screenWidth, screenHeight - footer, Colors::Text);
  }

  m_fullRedraw = false;
  m_redraw = false;
}
