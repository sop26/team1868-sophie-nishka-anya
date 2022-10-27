// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DrivetrainCommand.h"
#include <iostream>

DrivetrainCommand::DrivetrainCommand(Drivetrain& drivetrain,
                                     ControlBoard& humanControl)
    : _drivetrain{drivetrain}, _humanControl{humanControl} {
  AddRequirements(&drivetrain);
}

double GetDeadbandAdjustment(double value) {
  // std::cerr << value << std::endl;
  // if it's lower than the deadband, the robot should not move
  if (fabs(value) < DEADBAND_MAX) {
    return 0.0;
    // } else if (value > DEADBAND_MAX) {  // robot power is 0.0-1.0
    //   return (value - DEADBAND_MAX) / (1 - DEADBAND_MAX);
    // } else {
    //   return (value + DEADBAND_MAX) / (1 - DEADBAND_MAX);
  } else {
    return value;
  }
}

double GetCubicAdjustment(double value) {
  // return std::pow(value, 3.0);
  return value;
}

void DrivetrainCommand::Execute() {
  // if the left trigger is pressed use arcade drive
  // else use curvature drive
  double thrust =
      GetCubicAdjustment(GetDeadbandAdjustment(_humanControl.GetLeftY()));
  double rotation =
      GetCubicAdjustment(GetDeadbandAdjustment(_humanControl.GetRightX()));

  // double thrust =
  //     GetCubicAdjustment(GetDeadbandAdjustment(_humanControl.GetRightY()));
  // double rotation =
  //     GetCubicAdjustment(GetDeadbandAdjustment(_humanControl.GetLeftX()));
  _drivetrain.CurvatureDrive(
      thrust, (thrust < -DEADBAND_MAX) ? rotation : -rotation,
      _humanControl.GetRightBumper());  // true is allowTurnInPlace
}

// bool hint from top right trigger of the container
// to switch from drive mode one to the other: