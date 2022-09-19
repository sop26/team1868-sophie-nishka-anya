// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DrivetrainCommand.h"

DrivetrainCommand::DrivetrainCommand(Drivetrain& drivetrain,
                                     ControlBoard& humanControl)
    : _drivetrain{drivetrain}, _humanControl{humanControl} {
        AddRequirements(&drivetrain);
    }

void DrivetrainCommand::Execute() {
  // if the left trigger is pressed use arcade drive
  // else use curvature drive

//   if (_humanControl.GetLeftTrigger()) {
    // _drivetrain.ArcadeDrive(_humanControl.GetRightY(),
    //                         _humanControl.GetLeftX());
//   } else {
    _drivetrain.CurvatureDrive(_humanControl.GetRightY(),
                               _humanControl.GetLeftX(),
                               true);
                            //    _humanControl.GetLeftBumper());
//   }
}
// bool hint from top right trigger of the container
// to switch from drive mode one to the other: