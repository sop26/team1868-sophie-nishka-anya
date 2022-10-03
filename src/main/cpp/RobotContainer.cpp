// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  _drivetrain.SetDefaultCommand(_driveCommand);
  frc2::CommandScheduler::GetInstance().Schedule(&_driveCommand);

  
  
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

void RobotContainer::UpdateSensors() {
  
}

void RobotContainer::UpdateControls() {
  if (_controlBoard.GetFlywheelPrepDesired()) {
    frc2::CommandScheduler::GetInstance().Schedule(true, &_shootCommand);
    _ledController.UpdateShooting();
  } else {
    _ledController.Update();
  }
  // if (_controlBoard.GetFlywheelDesired()) {
  //   frc2::CommandScheduler::GetInstance().Schedule(true, &_shootCommand);
  //   _ledController.UpdateShooting();
  // }
  // else {
  //   _ledController.Update();
  // }
  _controlBoard.ReadControls();
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
