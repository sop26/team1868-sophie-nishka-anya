// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ControlBoard.h"

ControlBoard::ControlBoard() {
  _xbox = new frc::XboxController(0);
  // Implementation of subsystem construcr goes here.
}

double ControlBoard::GetLeftX() {
  return _xbox->GetLeftX();
}
double ControlBoard::GetRightX() {
  return _xbox->GetRightX();
}
double ControlBoard::GetLeftY() {
  return _xbox->GetLeftY();
}
double ControlBoard::GetRightY() {
  return _xbox->GetRightY();
}
