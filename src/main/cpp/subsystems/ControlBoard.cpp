// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {
  _leftPrimary = new WPI_TalonFX(0); 
  _leftSecondary = new WPI_TalonFX(0);
  _rightPrimary = new WPI_TalonFX(0);
  _rightSecondary = new WPI_TalonFX(0);
  _leftMotors = new frc::MotorControllerGroup(_leftPrimary, _leftSecondary);
  _rightMotors = new frc::MotorControllerGroup(_rightPrimary, _rightSecondary);
  MotorControllerGroup _drive = new DifferentialDrive(_leftMotors, _rightMotors);
  // Implementation of subsystem construcr goes here.
}

void Drivetrain::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Drivetrain::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void Drivetrain::SetMotorValue(double thrust, double rotation){

}