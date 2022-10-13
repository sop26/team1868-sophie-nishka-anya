// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "ControlBoard.h"
#include "subsystems/Drivetrain.h"
#include "commands/DrivetrainCommand.h"
#include "subsystems/Shooter.h"
#include "commands/ShooterCommand.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

 private:
  // The robot's subsystems and commands are defined here...
  Drivetrain _drivetrain{};
  Shooter _shooter{};
  ControlBoard _humanControl{};
  DrivetrainCommand _drivetrainCommand{_drivetrain, _humanControl};
  ShooterCommand _shooterCommand{_shooter, _humanControl};
  void ConfigureButtonBindings();
  bool _flywheelDesired;
};
