
#pragma once
#include "Ports.h"
#include <frc/AddressableLED.h>

class LEDController {
 public:
  LEDController();
  void Update();
  ~LEDController();

 private:
  int _hue, _firstPixelHue;
  frc::AddressableLED _ledStrip{LED_PORT};
  std::array<frc::AddressableLED::LEDData, LED_LENGTH> _ledBuffer;
};