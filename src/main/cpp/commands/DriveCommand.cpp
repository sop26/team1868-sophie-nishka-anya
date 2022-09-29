#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(Drivetrain& drivetrain, ControlBoard& controlboard)
    : _drivetrain{drivetrain}, _controlboard{controlboard} {
  AddRequirements(&drivetrain);
}

void DriveCommand::Execute() {
  _drivetrain.CurvatureDrive(
      -_controlboard.GetJoystickValue(ControlBoard::Joysticks::kLeftJoy,
                                      ControlBoard::Axes::kY),
      _controlboard.GetJoystickValue(ControlBoard::Joysticks::kRightJoy,
                                     ControlBoard::Axes::kX),
      true);
}