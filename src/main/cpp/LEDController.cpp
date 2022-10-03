#include "LEDController.h"

// Constructor - creates an LED controller!
LEDController::LEDController() {
  _hue = 1;
  _firstPixelHue = 1;

  for (int i = 0; i < LED_LENGTH; i++) {
    if (i % 2 == 0) {
      _ledBuffer[i].SetHSV(_hue, LED_SAT, LED_VAL);
    }
  }

  _ledStrip.SetLength(LED_LENGTH);
  _ledStrip.SetData(_ledBuffer);
  _ledStrip.Start();
}

// Updates LED state
void LEDController::Update() {
  for (int i = 0; i < LED_LENGTH; i++) {
    const auto pixelHue = (_firstPixelHue + (i * 180 / LED_LENGTH)) % 180;
    _ledBuffer[i].SetHSV(pixelHue, 200, 70);
  }
  _firstPixelHue += 3;
  _firstPixelHue %= 180;
  _ledStrip.SetData(_ledBuffer);
}

void LEDController::UpdateShooting() {
    _secondaryCounter += 1;
    if (_secondaryCounter > 5) {
        _counter++;
        _secondaryCounter = 0;
    }
    for (int i = 0; i < LED_LENGTH; i++) {
        if ((i + _counter) % 6 < 3) {
            _ledBuffer[i].SetHSV(0, 200, 70);
        }
        else {
            _ledBuffer[i].SetHSV(180, 200, 70);
        }
    }
    _ledStrip.SetData(_ledBuffer);
    
   
}

// Destructor
LEDController::~LEDController() {}