
#pragma once
#include "Ports.h"
#include <frc/AddressableLED.h>

class LEDController {
 public:
  LEDController();
  void Update();
  void UpdateShooting();
  ~LEDController();

 private:
  int _hue, _firstPixelHue;
  int _counter = 0;
  int _secondaryCounter = 0;
  frc::AddressableLED _ledStrip{LED_PORT};
  std::array<frc::AddressableLED::LEDData, LED_LENGTH> _ledBuffer;
};