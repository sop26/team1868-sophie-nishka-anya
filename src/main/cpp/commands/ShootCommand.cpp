#include "commands/ShootCommand.h"

ShootCommand::ShootCommand(Shooter& shooter, ControlBoard& controlBoard,
                           LEDController& ledController)
    : _shooter{shooter},
      _controlBoard{controlBoard},
      _ledController{ledController} {
  AddRequirements(&shooter);
}

void ShootCommand::Execute() {
  _ledController.UpdateShooting();
  _shooter.SetFlywheelOutput(_controlBoard.GetFlywheelJoystickValue());
  _shooter.SetFlywheelFeederOutput(0.5);
}

void ShootCommand::End(bool interrupted) {
  _shooter.SetFlywheelOutput(0.0);
  _shooter.SetFlywheelFeederOutput(0.0);
}
