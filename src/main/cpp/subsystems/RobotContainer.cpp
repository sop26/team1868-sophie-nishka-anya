// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  _drivetrain.SetDefaultCommand(_driveCommand);
  _controlBoard._prepFlywheelButton.WhenPressed(_shootCommand);
  _controlBoard._flywheelButton.WhenPressed(_shootCommand);
}

void RobotContainer::UpdateLEDs() {
  _controlBoard.GetPrepFlywheelDesired() ? _ledController.UpdateShooting()
                                         : _ledController.Update();
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
