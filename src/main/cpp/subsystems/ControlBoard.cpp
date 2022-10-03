/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlBoard.h"

ControlBoard::ControlBoard() {
  _leftJoyX = 0.0;
  _leftJoyY = 0.0;
  _rightJoyX = 0.0;
  _rightJoyY = 0.0;
  _flywheelJoyX = 0.0;

  _flywheelDesired = false;
  _flywheelPrepDesired = false;
  ReadControls();
}

void ControlBoard::ReadControls() {
  ReadAllButtons();
  // Reading joystick values
  _leftJoyX = leftJoy_.GetX();
  _leftJoyY = leftJoy_.GetY();

  _rightJoyX = rightJoy_.GetX();
  _rightJoyY = rightJoy_.GetY();

  _flywheelJoyX = operatorJoyB_.GetX();
  _flywheelDesired = flywheelButton_.IsDown();
  _flywheelPrepDesired = flywheelPrepButton_.IsDown();
}

bool ControlBoard::GetFlywheelDesired() {
  return _flywheelDesired;
  
}

bool ControlBoard::GetFlywheelPrepDesired() {
  return _flywheelPrepDesired;
}

double ControlBoard::GetJoystickValue(Joysticks j, Axes a) {
  switch (j) {
    case (kLeftJoy):
      switch (a) {
        case (kX):
          return _leftJoyX;
        case (kY):
          return _leftJoyY;
        default:
          printf("WARNING: no joystick given (left)\n");
          return 0.0;
      }
      break;
    case (kRightJoy):
      switch (a) {
        case (kX):
          return _rightJoyX;
        case (kY):
          return _rightJoyY;
        default:
          printf("WARNING: no joystick given (right)\n");
          return 0.0;
      }
      break;
    default:
      printf(
          "WARNING: Joystick value not received in "
          "ControlBoard::GetJoystickValue\n");
  }
  return 0;
}

double ControlBoard::GetFlywheelJoystickValue() {
  return _flywheelJoyX;
}

void ControlBoard::ReadAllButtons() {
  flywheelButton_.ReadValue();
  flywheelPrepButton_.ReadValue();
}

ControlBoard::~ControlBoard() {}
