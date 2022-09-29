#include "commands/ShootCommand.h"

ShootCommand::ShootCommand(Shooter& shooter, ControlBoard& controlBoard)
    : _shooter{shooter}, _controlBoard{controlBoard} {
  AddRequirements(&shooter);
}

void ShootCommand::Execute() {
  if (_controlBoard.GetFlywheelDesired()) {
    _shooter.SetFlywheelOutput(_controlBoard.GetFlywheelJoystickValue());
  } else {
    _shooter.SetFlywheelOutput(0.0);
  }

  if (_controlBoard.GetFlywheelPrepDesired()) {
    _shooter.SetFlywheelPrepOutput(0.5);
  } else {
    _shooter.SetFlywheelPrepOutput(0.0);
  }
}