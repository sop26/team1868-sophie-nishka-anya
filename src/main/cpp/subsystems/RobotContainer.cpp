// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RobotContainer.h"

RobotContainer::RobotContainer() {
  ///* store the commands and reuse them*/
  _drivetrain.SetDefaultCommand(_drivetrainCommand);
  frc2::CommandScheduler::GetInstance().Schedule(&_drivetrainCommand);

  _shooter.SetDefaultCommand(_shooterCommand);
  frc2::CommandScheduler::GetInstance().Schedule(&_shooterCommand);
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

// An example command will be run in autonomous

// declaring = know that they exist
// defining = set what the things (that are defined) are equal to
