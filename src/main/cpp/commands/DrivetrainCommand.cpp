// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DrivetrainCommand.h"

DrivetrainCommand::DrivetrainCommand(Drivetrain* Drivetrain)
    : m_subsystem{Drivetrain} {}


void DrivetrainCommand::Execute(){

}

void DrivetrainCommand::Execute() {
    driveTrain_->ArcadeDrive(humanControl_->GetRightJoyY(), humanControl_->GetLeftJoyX());
    //driveTrain_->ArcadeDrive(-humanControl_->GetRightJoyY(), humanControl_->GetLeftJoyX());
}
