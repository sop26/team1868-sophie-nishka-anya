// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ControlBoard.h"
#include "CONSTANTS.h"

ControlBoard::ControlBoard() {
  // Implementation of subsystem construcr goes here.
}

// double ControlBoard::GetLeftX() {
//   return _xbox.GetLeftX();
// }
// double ControlBoard::GetRightX() {
//   return _xbox.GetRightX();
// }
// double ControlBoard::GetLeftY() {
//   return _xbox.GetLeftY();
// }
// double ControlBoard::GetRightY() {
//   return _xbox.GetRightY();
// }

// bool ControlBoard::GetLeftBumper() {
//   return _xbox.GetLeftBumper();
// }

// bool ControlBoard::GetLeftTrigger() {
//   return _xbox.GetLeftTriggerAxis() > LEFT_TRIGGER_BARRIER;
// }

// bool ControlBoard::GetRightTrigger(){
//   return _xbox.GetRightTriggerAxis() > RIGHT_TRIGGER_BARRIER;
// }

double ControlBoard::GetLeftX() {
  return _leftJoy.GetX();
}
double ControlBoard::GetRightX() {
  return _rightJoy.GetX();
}
double ControlBoard::GetLeftY() {
  return _leftJoy.GetY();
}
double ControlBoard::GetRightY() {
  return _rightJoy.GetY();
}

// bool ControlBoard::GetLeftBumper() {
//   return _xbox.GetLeftBumper();
// }

// bool ControlBoard::GetLeftTrigger() {
//   return _xbox.GetLeftTriggerAxis() > LEFT_TRIGGER_BARRIER;
// }

// bool ControlBoard::GetRightTrigger(){
//   return _xbox.GetRightTriggerAxis() > RIGHT_TRIGGER_BARRIER;
// }

bool ControlBoard::IsPressed(frc::Joystick& joystick, int PORT) {
  _operatorJoyB.GetRawButtonPressed(PORT);
}

bool ControlBoard::IsReleased(frc::Joystick& joystick, int PORT) {
  _operatorJoyB.GetRawButtonReleased(PORT);
}

bool ControlBoard::GetFlywheelDesired() {
  return _flywheelDesired;
}

bool ControlBoard::GetFlywheelPrepDesired() {
  return _flywheelPrepDesired;
}

bool ControlBoard::GetFlywheelReset() {
  return _flywheelReset;
}

bool ControlBoard::GetFlywheelPrepReset() {
  return _flywheelPrepReset;
}

void ControlBoard::Update() {
  _flywheelDesired = IsPressed(_flywheelButton, FLYWHEEL_BUTTON_PORT);
  _flywheelPrepDesired =
      IsPressed(_flywheelPrepButton, FLYWHEEL_PREP_BUTTON_PORT);
  _flywheelReset = IsReleased(_flywheelButton, FLYWHEEL_BUTTON_PORT);
  _flywheelPrepReset = IsReleased(_flywheelButton, FLYWHEEL_BUTTON_PORT);
}
