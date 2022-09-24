// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShooterCommand.h"

ShooterCommand::ShooterCommand(Shooter& shooter,
                                     ControlBoard& humanControl)
    : _shooter{shooter}, _humanControl{humanControl} {
        AddRequirements(&shooter);
    }

void ShooterCommand::Execute(){
    if(_humanControl.GetLeftTrigger()){
        _shooter.SetFlywheelOutput(.75);
    }
    if(_humanControl.GetRightTrigger()){
        _shooter.SetFlywheelPrepOutput(.5);
    }
}