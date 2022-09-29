// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ControlBoard.h"
#include "CONSTANTS.h"


ControlBoard::ControlBoard() {
  _flywheelDesired = IsDown(_flywheelButton, FLYWHEEL_BUTTON_PORT);
	_flywheelPrepDesired = IsDown(_flywheelPrepButton, FLYWHEEL_PREP_BUTTON_PORT);
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


// bool ControlBoard::GetX(){
//   return _flywheelJoyX.GetX();
// }

bool ControlBoard::IsDown(frc::Joystick &joystick, int PORT){
  _operatorJoyB.GetRawButton(PORT);
}


bool ControlBoard::GetFlywheelDesired(){
  return _flywheelDesired;
}

bool ControlBoard::GetFlywheelPrepDesired(){
  return _flywheelPrepDesired;
}


void ControlBoard::Update(){
  _flywheelDesired = IsDown(_flywheelButton, FLYWHEEL_BUTTON_PORT);
	_flywheelPrepDesired = IsDown(_flywheelPrepButton, FLYWHEEL_PREP_BUTTON_PORT);
}

