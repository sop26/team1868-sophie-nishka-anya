// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  _drivetrain.SetDefaultCommand(_driveCommand);
  frc2::CommandScheduler::GetInstance().Schedule(&_driveCommand);

  _shooter.SetDefaultCommand(_shootCommand);
  frc2::CommandScheduler::GetInstance().Schedule(&_shootCommand);
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

void RobotContainer::UpdateSensors() {
  _ledController.Update();
}

void RobotContainer::UpdateControls() {
  _controlBoard.ReadControls();
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
