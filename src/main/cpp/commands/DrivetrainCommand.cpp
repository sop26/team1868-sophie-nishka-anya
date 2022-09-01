// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DrivetrainCommand.h"

DrivetrainCommand::DrivetrainCommand(Drivetrain* _drivetrain, ControlBoard* _humanControl)
    : _drivetrain{_drivetrain} {
        _humanControl = _humanControl;
    }
   



void DrivetrainCommand::Execute() {
    _drivetrain->ArcadeDrive(_humanControl->GetRightY(), _humanControl->GetLeftX());
}
