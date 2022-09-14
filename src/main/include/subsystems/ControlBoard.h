
#pragma once
#include "subsystems/PORTS.h"
#include <frc/XboxController.h>

class ControlBoard {
 public:
  ControlBoard();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  double GetLeftX();
  double GetRightX();
  double GetLeftY();
  double GetRightY();
  double GetLeftBumper();

 private:
  // Joysticks for drive

  frc::XboxController* _xbox;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};