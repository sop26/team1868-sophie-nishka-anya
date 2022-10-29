#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"
#include "ControlBoard.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveCommand
    : public frc2::CommandHelper<frc2::CommandBase, DriveCommand> {
 public:
  // DriveCommand(Drivetrain* drivetrain, std::function<double()> forward,
  // std::function<double()> rotation);
  DriveCommand(Drivetrain& drivetrain, ControlBoard& controlboard);

  void Execute() override;

 private:
  Drivetrain& _drivetrain;
  ControlBoard& _controlboard;
  // std::function<double()> m_forward;
  // std::function<double()> m_rotation;
};
