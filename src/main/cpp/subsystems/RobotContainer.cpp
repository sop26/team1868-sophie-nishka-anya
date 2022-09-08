// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RobotContainer.h"


RobotContainer::RobotContainer(){
  // Initialize all of your commands and subsystems here
  _drivetrain = new Drivetrain();
  _humanControl = new ControlBoard();
  _drivetrainCommand = new DrivetrainCommand(_drivetrain, _humanControl);
///* store the commands and reuse them*/

  _drivetrain->SetDefaultCommand(*_drivetrainCommand);

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}


  // An example command will be run in autonomous
  

//declaring = know that they exist 
// defining = set what the things (that are defined) are equal to 