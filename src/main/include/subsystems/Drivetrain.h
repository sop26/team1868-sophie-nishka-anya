// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "ControlBoard.h"

class Drivetrain: public frc2::SubsystemBase {
 public:
  Drivetrain();
  void SetMotorValue(double thrust, double rotation);
  void ArcadeDrive(double thrust, double rotation);

  
 private:
  WPI_TalonSRX *_leftPrimary, *_leftSecondary, *_rightPrimary, *_rightSecondary;
  frc::MotorControllerGroup *_leftMotors, *_rightMotors;
  frc::DifferentialDrive *_drive;
  // MotorControllerGroup _drive = new DifferentialDrive(_leftMotors, _rightMotors);
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
