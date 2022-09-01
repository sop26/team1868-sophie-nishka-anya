// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include <rev/CANSparkMax.h>


Drivetrain::Drivetrain() {
  _leftPrimary = new WPI_TalonSRX(0); 
  _leftSecondary = new WPI_TalonSRX(0);
  _rightPrimary = new WPI_TalonSRX(0);
  _rightSecondary = new WPI_TalonSRX(0);
  _leftMotors = new frc::MotorControllerGroup(*_leftPrimary, *_leftSecondary);
  _rightMotors = new frc::MotorControllerGroup(*_rightPrimary, *_rightSecondary);
  _drive = new frc::DifferentialDrive(*_leftMotors, *_rightMotors);
  // Implementation of subsystem construcr goes here.
}

void Drivetrain::ArcadeDrive(double thrust, double rotation){
  _drive->ArcadeDrive (thrust, rotation);
} 



void Drivetrain::SetMotorValue(double thrust, double rotation){

}