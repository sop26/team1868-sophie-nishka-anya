#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"
#include "ControlBoard.h"
#include "LEDController.h"

class PrepShotCommand
    : public frc2::CommandHelper<frc2::CommandBase, PrepShotCommand> {
 public:
  PrepShotCommand(Shooter& shooter, ControlBoard& controlBoard,
                  LEDController& ledController);

  void Execute() override;
  void End(bool interrupted) override;

 private:
  Shooter& _shooter;
  ControlBoard& _controlBoard;
  LEDController& _ledController;
};
