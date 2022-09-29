/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ButtonReader.h"
// #include <frc/WPILib.h>
#include <frc/Joystick.h>

// class ButtonReader
// constructs a joystick and sets the port of the button on the joystick, and
// reads the state of the button

ButtonReader::ButtonReader(frc::Joystick* myJoystick, int myButtonNum) {
  _joystick = myJoystick;
  _buttonNum = myButtonNum;
  _currState = _joystick->GetRawButton(_buttonNum);
  _lastState = _currState;
}

void ButtonReader::ReadValue() {
  _lastState = _currState;
  _currState = _joystick->GetRawButton(_buttonNum);
}

bool ButtonReader::WasJustPressed() {
  return (_lastState == false && _currState == true);
}

bool ButtonReader::WasJustReleased() {
  return (_lastState == true && _currState == false);
}

bool ButtonReader::StateJustChanged() {
  return (_lastState != _currState);
}

bool ButtonReader::IsDown() {
  return _currState;
}

ButtonReader::~ButtonReader() {}

ToggleButtonReader::ToggleButtonReader(frc::Joystick* joy, int buttonNum)
    : ButtonReader(joy, buttonNum) {
  _currToggleState = false;
}

// gets the current state of the toggle
bool ToggleButtonReader::GetState() {
  if (WasJustReleased()) {
    _currToggleState = !_currToggleState;
  }
  return (_currToggleState);
}

ToggleButtonReader::~ToggleButtonReader() {}

SwitchReader::SwitchReader(frc::Joystick* myJoy, int upButton, int downButton) {
  _joy = myJoy;
  _upB = upButton;
  _downB = downButton;
}

SwitchState SwitchReader::GetSwitchState() {
  if (_joy->GetRawButton(_upB))
    return kUp;
  if (_joy->GetRawButton(_downB))
    return kDown;
  return kNeutral;
}