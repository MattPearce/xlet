#include <DI.h>
#include <M5Stack.h>
#include "Display/M5StackDisplay.h"
#include "Input/M5StackInput.h"
#include "Network/M5StackBluetoothAdapter.h"
#include "M5StackTarget.h"

void InitTarget()
{
  // Initialize the M5Stack object
  M5.begin();

  DISingleton(IDisplay, M5StackDisplay);
  DISingleton(IInput, M5StackInput);
  DISingleton(IBluetoothAdapter, M5StackBluetoothAdapter);
}
