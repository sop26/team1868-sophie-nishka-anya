#include "commands/ShootCommand.h"

ShootCommand::ShootCommand(Shooter& shooter, ControlBoard& controlBoard)
    : _shooter{shooter}, _controlBoard{controlBoard} {
  _shooter.SetFlywheelOutput(_controlBoard.GetFlywheelJoystickValue());
  AddRequirements(&shooter);
}

void ShootCommand::Execute() {
  _shooter.SetFlywheelOutput(_controlBoard.GetFlywheelJoystickValue());
  if (_controlBoard.GetFlywheelDesired()) {
    _shooter.SetFlywheelPrepOutput(0.5);
  }
  else {
    _shooter.SetFlywheelPrepOutput(0.0);
  }
}

void ShootCommand::End(bool interrupted) {
  _shooter.SetFlywheelOutput(0.0);
  _shooter.SetFlywheelPrepOutput(0.0);
}

bool ShootCommand::IsFinished() {
  return !_controlBoard.GetFlywheelPrepDesired();
}