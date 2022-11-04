#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"
#include "ControlBoard.h"

class DriveCommand
    : public frc2::CommandHelper<frc2::CommandBase, DriveCommand> {
 public:
  DriveCommand(Drivetrain& drivetrain, ControlBoard& controlboard);
  void Execute() override;

 private:
  Drivetrain& _drivetrain;
  ControlBoard& _controlboard;
};
