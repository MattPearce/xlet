// Framework includes
#include <Arduino.h>

// Target includes
#include <DI.h>
#include <Display/IDisplay.h>
#include <Input/IInput.h>
#include <Network/IBluetoothAdapter.h>

// Local includes
#include "UI/MainMenu.h"
#include "UI/PaymentConfirm.h"
#include "Targets.h"
#include "Constants.h"

DI<IDisplay> display;
DI<IInput> input;
DI<IBluetoothAdapter> bluetooth;
std::shared_ptr<IScreen> screen;

void setup(){
  InitTarget();

  display = DI(IDisplay);
  input = DI(IInput);
  bluetooth = DI(IBluetoothAdapter);

  auto bluetoothAdapter = bluetooth->GetInstance();

  bluetoothAdapter->Initialise();

  auto serviceUUID = Constants::Bluetooth::StellarPaymentService::ServiceUUID;
  auto paymentRequestUUID = Constants::Bluetooth::StellarPaymentService::Characteristics::PaymentRequestUUID;
  auto paymentResponseUUID = Constants::Bluetooth::StellarPaymentService::Characteristics::PaymentResponseUUID;

  bluetoothAdapter->CreateService(serviceUUID);

  bluetoothAdapter->CreateCharacteristic(serviceUUID, paymentResponseUUID);

  bluetoothAdapter->CreateCharacteristic(serviceUUID, paymentRequestUUID);

  screen = std::make_shared<MainMenu>();

  bluetoothAdapter->SetCharacteristicWriteHandler(paymentRequestUUID, [&](const std::string& value) {
    auto confirm = std::make_shared<PaymentConfirm>(value);

    confirm->OnConfirm([](){
      screen = std::make_shared<MainMenu>();
    });

    screen = confirm;
  });

  bluetoothAdapter->StartService(serviceUUID);

  bluetoothAdapter->StartAdvertising();
}

// the loop routine runs over and over again forever
void loop() {
  auto inputEvents = input->GetInstance()->GetEvents();

  screen->Update(inputEvents);

  screen->Draw(display->GetInstance());
}
