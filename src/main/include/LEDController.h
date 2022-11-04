
#pragma once

#include <frc/AddressableLED.h>

#include "Ports.h"

class LEDController {
 public:
  LEDController();
  void Update();
  void UpdateShooting();

 private:
  int _hue = 1;
  int _firstPixelHue = 1;
  int _counter = 0;
  int _secondaryCounter = 0;
  frc::AddressableLED _ledStrip{LED_PORT};
  std::array<frc::AddressableLED::LEDData, LED_LENGTH> _ledBuffer;
};
