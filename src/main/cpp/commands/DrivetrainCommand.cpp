#include "commands/DrivetrainCommand.h"

DriveCommand::DriveCommand(Drivetrain& drivetrain, ControlBoard& controlboard)
    : _drivetrain{drivetrain}, _controlboard{controlboard} {
  AddRequirements(&drivetrain);
}

void DriveCommand::Execute() {
  auto y = _controlboard.GetLeftJoyY();
  auto x = _controlboard.GetRightJoyX();
  x = fabs(x) < 0.08 ? 0 : x;
  y = fabs(y) < 0.08 ? 0 : y;

  _drivetrain.CurvatureDrive(y, (y >= 0) ? x : -x, true);
}
