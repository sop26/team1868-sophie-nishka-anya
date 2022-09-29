
#pragma once
#include "PORTS.h"
#include <frc/Joystick.h>
#include <frc/XboxController.h>



class ControlBoard {
 public:
  ControlBoard();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  // double GetLeftX();
  // double GetRightX();
  // double GetLeftY();
  // double GetRightY();
  // bool GetLeftBumper();
  // bool GetLeftTrigger();
  // bool GetRightTrigger();

 
  double GetLeftX();
  double GetRightX();
  double GetLeftY();
  double GetRightY();

  
  bool GetX();
  bool GetFlywheelDesired();
  bool GetFlywheelPrepDesired();
  bool IsDown(frc::Joystick &joystick, int PORT);
  void Update();


 private:
  // Joysticks for drive

  // frc::XboxController _xbox{XBOX_DRIVER_PORT};
  frc::Joystick _leftJoy{LEFT_JOYSTICK_DRIVER_PORT};
  frc::Joystick _rightJoy{RIGHT_JOYSTICK_DRIVER_PORT};
  frc::Joystick _operatorJoyB{OPERATOR_JOY_B_USB_PORT};
  // frc::Joystick _flywheelJoyX{FLYWHEEL_JOY_X_PORT};
  bool _flywheelDesired;
  bool _flywheelPrepDesired;
  frc::Joystick _flywheelButton{FLYWHEEL_BUTTON_PORT};
  frc::Joystick _flywheelPrepButton{FLYWHEEL_PREP_BUTTON_PORT};
  
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};