#include "commands/ShootCommand.h"

ShootCommand::ShootCommand(Shooter& shooter, ControlBoard& controlBoard)
    : _shooter{shooter}, _controlBoard{controlBoard} {
  AddRequirements(&shooter);
}

void ShootCommand::Execute() {
  _shooter.SetFlywheelOutput(_controlBoard.GetFlywheelJoystickValue());
  _shooter.SetFlywheelPrepOutput(_controlBoard.GetFlywheelDesired() ? 0.5
                                                                    : 0.0);
}

void ShootCommand::End(bool interrupted) {
  _shooter.SetFlywheelOutput(0.0);
  _shooter.SetFlywheelPrepOutput(0.0);
}

bool ShootCommand::IsFinished() {
  return !_controlBoard.GetPrepFlywheelDesired();
}