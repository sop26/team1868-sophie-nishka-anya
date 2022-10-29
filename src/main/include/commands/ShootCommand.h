#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"
#include "ControlBoard.h"
#include "LEDController.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ShootCommand
    : public frc2::CommandHelper<frc2::CommandBase, ShootCommand> {
 public:
  // DriveCommand(Drivetrain* drivetrain, std::function<double()> forward,
  // std::function<double()> rotation);
  ShootCommand(Shooter& shooter, ControlBoard& controlBoard);

  void Execute() override;
  bool IsFinished();
  void End(bool interrupted) override;

 private:
  Shooter& _shooter;
  ControlBoard& _controlBoard;
};
