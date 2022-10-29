/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
// #include <frc/WPILib.h>
#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include "PORTS.h"

class ControlBoard {
 public:
  ControlBoard();

  bool GetFlywheelDesired();
  bool GetPrepFlywheelDesired();
  double GetFlywheelJoystickValue();
  double GetLeftJoyX();
  double GetLeftJoyY();
  double GetRightJoyX();
  double GetRightJoyY();
  double GetFlywheelX();

 private:
  // Joysticks for drive
  frc::Joystick leftJoy_{LEFT_JOY_USB_PORT};
  frc::Joystick rightJoy_{RIGHT_JOY_USB_PORT};

  // Joysticks for operator
  frc::Joystick operatorJoy_{OPERATOR_JOY_USB_PORT};
  frc::Joystick operatorJoyB_{OPERATOR_JOY_B_USB_PORT};

 public:
  frc2::JoystickButton _flywheelButton{&operatorJoyB_, FLYWHEEL_BUTTON_PORT};
  frc2::JoystickButton _prepFlywheelButton{&operatorJoyB_,
                                           PREP_FLYWHEEL_BUTTON_PORT};
};
