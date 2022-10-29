/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
// #include <frc/WPILib.h>
#include <frc/Joystick.h>
#include "Ports.h"

class ControlBoard {
 public:
  enum Joysticks { kLeftJoy, kRightJoy };
  enum Axes { kX, kY };

  ControlBoard();

  void ReadAllButtons();
  bool GetFlywheelDesired();
  bool GetFlywheelPrepDesired();
  double GetFlywheelJoystickValue();
  double GetLeftJoyX();
  double GetLeftJoyY();
  double GetRightJoyX();
  double GetRightJoyY();
  double GetFlywheelX();

  ~ControlBoard();

 private:
  // Joysticks for drive
  frc::Joystick leftJoy_{LEFT_JOY_USB_PORT};
  frc::Joystick rightJoy_{RIGHT_JOY_USB_PORT};

  // Joysticks for operator
  frc::Joystick operatorJoy_{OPERATOR_JOY_USB_PORT};
  frc::Joystick operatorJoyB_{OPERATOR_JOY_B_USB_PORT};
};
