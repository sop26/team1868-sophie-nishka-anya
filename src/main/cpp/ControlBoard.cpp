/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ControlBoard.h"

ControlBoard::ControlBoard() {}

double ControlBoard::GetLeftJoyX() {
  return leftJoy_.GetX();
}
double ControlBoard::GetLeftJoyY() {
  return leftJoy_.GetY();
}
double ControlBoard::GetRightJoyX() {
  return rightJoy_.GetX();
}
double ControlBoard::GetRightJoyY() {
  return rightJoy_.GetX();
}
double ControlBoard::GetFlywheelJoystickValue() {
  return operatorJoyB_.GetX();
}

bool ControlBoard::GetFlywheelDesired() {
  return operatorJoyB_.GetRawButton(FLYWHEEL_BUTTON_PORT);
}

bool ControlBoard::GetFlywheelPrepDesired() {
  return operatorJoyB_.GetRawButton(FLYWHEEL_PREP_BUTTON_PORT);
}

ControlBoard::~ControlBoard() {}
