#include "commands/DrivetrainCommand.h"

DriveCommand::DriveCommand(Drivetrain& drivetrain, ControlBoard& controlboard)
    : _drivetrain{drivetrain}, _controlboard{controlboard} {
  AddRequirements(&drivetrain);
}

void DriveCommand::Execute() {
  _drivetrain.CurvatureDrive(-_controlboard.GetLeftJoyY(),
                             _controlboard.GetRightJoyX(), true);
}