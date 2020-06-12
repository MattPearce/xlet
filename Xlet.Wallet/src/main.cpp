#include <Arduino.h>
#include <M5Stack.h>
#include <string>
#include "Icons/Icons.h"
#include "Constants.h"
#include <DI.h>
#include <Display/IDisplay.h>
#include "Targets.h"

class MenuButton
{
public:
  std::string Text;

  Xlet::Icons::Icon* Icon;
  Xlet::Icons::Icon* IconActive;
};

IDisplay* display;

void DrawIcon(int x, int y, const Xlet::Icons::Icon* icon)
{
  display->DrawBitmap(x, y, icon->GetWidth(), icon->GetHeight(), icon->GetImage());
}

Xlet::Icons::Battery iconBattery;
Xlet::Icons::Bluetooth iconBluetooth;
Xlet::Icons::Up iconUp;
Xlet::Icons::Check iconCheck;
Xlet::Icons::Down iconDown;

void draw(int menuOption)
{
  const int ButtonHeight = ((Constants::Size::ScreenHeight - Constants::Size::Header - Constants::Size::Footer) - ((Constants::Size::ButtonsPerPage + 1) * Constants::Size::ButtonMargin)) / Constants::Size::ButtonsPerPage;

  MenuButton buttons[] = {
    { "Pay", new Xlet::Icons::Money(), new Xlet::Icons::MoneyActive() },
    { "Receive", new Xlet::Icons::QR(), new Xlet::Icons::QRActive() },
    { "History", new Xlet::Icons::Receipt(), new Xlet::Icons::ReceiptActive() },
    { "Settings", new Xlet::Icons::Cog(), new Xlet::Icons::CogActive() }
  };

  for(int i = 0; i < Constants::Size::ButtonsPerPage; ++i)
  {
    int y = Constants::Size::Header + (Constants::Size::ButtonMargin * (i + 1)) + ButtonHeight * i;
    int w = Constants::Size::ScreenWidth - (Constants::Size::ButtonMargin * 2);

    if(i == menuOption) {
      display->FillRoundRect(Constants::Size::ButtonMargin, y, w, ButtonHeight, 5, Constants::Palette::ButtonHighlight);
      display->DrawRoundRect(Constants::Size::ButtonMargin, y, w, ButtonHeight, 5, Constants::Palette::Text);
      DrawIcon(Constants::Size::ButtonMargin + 3, y + 3, buttons[i].IconActive);
    } else {
      display->FillRoundRect(Constants::Size::ButtonMargin, y, w, ButtonHeight, 5, Constants::Palette::Button);
      DrawIcon(Constants::Size::ButtonMargin + 3, y + 3, buttons[i].Icon);
    }

    display->DrawString(buttons[i].Text.c_str(), Constants::Size::ButtonMargin + 38, y+9, 4, Constants::Palette::TextMenu);
  }

  // LCD display
  display->DrawString("1:45pm", Constants::Size::ButtonMargin, 9, 1, Constants::Palette::Text);
  
  DrawIcon(Constants::Size::ScreenWidth - Constants::Size::ButtonMargin - 16, 3, &iconBattery);
  DrawIcon(Constants::Size::ScreenWidth - Constants::Size::ButtonMargin - 32, 3, &iconBluetooth);

  DrawIcon(52, Constants::Size::ScreenHeight - 32, &iconUp);
  DrawIcon(144, Constants::Size::ScreenHeight - 32, &iconCheck);
  DrawIcon(238, Constants::Size::ScreenHeight - 32, &iconDown);
  
  display->DrawLine(0, Constants::Size::ScreenHeight - Constants::Size::Footer, Constants::Size::ScreenWidth, Constants::Size::ScreenHeight - Constants::Size::Footer, Constants::Palette::Text);
}

// the setup routine runs once when M5Stack starts up
void setup(){
  InitTarget();

  display = DI(IDisplay)->GetInstance();

  display->FillScreen(Constants::Palette::Background);

  draw(0);
}

int menuOption = 0;
bool aWasPressed = false;
bool bWasPressed = false;
bool cWasPressed = false;

// the loop routine runs over and over again forever
void loop() {
  M5.update();

  bool aIsPressed = M5.BtnA.read();
  bool bIsPressed = M5.BtnB.read();
  bool cIsPressed = M5.BtnC.read();

  if(aIsPressed && !aWasPressed) {
    --menuOption;

    if(menuOption < 0) {
      menuOption = 3;
    }

    draw(menuOption);
  }

  if(bIsPressed && !bWasPressed && menuOption == 1) {
    display->FillScreen(Constants::Palette::Background);

    //M5.Lcd.qrcode("GBBM6BKZPEHWYO3E3YKREDPQXMS4VK35YLNU7NFBRI26RAN7GI5POFBB");
  }

  if(cIsPressed && !cWasPressed) {
    ++menuOption;

    if(menuOption > 3) {
      menuOption = 0;
    }

    draw(menuOption);
  }

  aWasPressed = aIsPressed;
  bWasPressed = bIsPressed;
  cWasPressed = cIsPressed;
}
