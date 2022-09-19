// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "ControlBoard.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  void ArcadeDrive(double thrust, double rotation);
  void CurvatureDrive(double thrust, double rotation, bool allowTurnInPlace);

 private:
  WPI_TalonSRX _leftPrimary{LEFT_PRIMARY_ID};
  WPI_TalonSRX _leftSecondary{LEFT_SECONDARY_ID};
  WPI_TalonSRX _rightPrimary{RIGHT_PRIMARY_ID};
  WPI_TalonSRX _rightSecondary{RIGHT_SECONDARY_ID};
  frc::MotorControllerGroup _leftMotors{_leftPrimary, _leftSecondary};
  frc::MotorControllerGroup _rightMotors{_rightPrimary, _rightSecondary};
  frc::DifferentialDrive _drive{_rightMotors, _leftMotors};
  // Components (e.g. motor controllers and sensors) should
  // generally be declared private and exposed only through public methods.
};
