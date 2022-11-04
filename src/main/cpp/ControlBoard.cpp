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

bool ControlBoard::GetPrepFlywheelDesired() {
  return operatorJoyB_.GetRawButton(PREP_FLYWHEEL_BUTTON_PORT);
}
