#include "commands/PrepShotCommand.h"

PrepShotCommand::PrepShotCommand(Shooter& shooter, ControlBoard& controlBoard,
                                 LEDController& ledController)
    : _shooter{shooter},
      _controlBoard{controlBoard},
      _ledController{ledController} {
  AddRequirements(&shooter);
}

void PrepShotCommand::Execute() {
  if (_controlBoard.GetPrepFlywheelDesired()) {
    _ledController.UpdateShooting();
    _shooter.SetFlywheelOutput(_controlBoard.GetFlywheelJoystickValue());
  } else {
    _shooter.SetFlywheelOutput(0);
    _ledController.Update();
  }
}

void PrepShotCommand::End(bool interrupted) {
  _shooter.SetFlywheelOutput(0.0);
}
