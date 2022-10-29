#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"
#include "ControlBoard.h"
#include "LEDController.h"

class ShootCommand
    : public frc2::CommandHelper<frc2::CommandBase, ShootCommand> {
 public:
  ShootCommand(Shooter& shooter, ControlBoard& controlBoard);

  void Execute() override;
  bool IsFinished();
  void End(bool interrupted) override;

 private:
  Shooter& _shooter;
  ControlBoard& _controlBoard;
};
