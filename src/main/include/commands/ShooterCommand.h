// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"


class ShooterCommand
    : public frc2::CommandHelper<frc2::CommandBase, ShooterCommand> {
 public:
  void Execute() override;
    
   
  ShooterCommand(Shooter& shooter, ControlBoard& humanControl);

 private:
  Shooter& _shooter;
  ControlBoard& _humanControl;
};
