// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {
  _rightMotors.SetInverted(true);
  // Implementation of subsystem constructor goes here.
}

void Drivetrain::Periodic() {
  _odometry.Update(_gyro.GetRotation2d(),
                   units::degree_t{_leftEncoder.GetDistance()},
                   units::degree_t{_rightEncoder.GetDistance()});
  _fieldSim.SetRobotPose(_odometry.GetPose());
}

void Drivetrain::SimulationPeriodic() {
  // To update our simulation, we set motor voltage inputs, update the
  // simulation, and write the simulated positions and velocities to our
  // simulated encoder and gyro. We negate the right side so that positive
  // voltages make the right side move forward.
  _drivetrainSim.SetInputs(units::volt_t{_leftMotors.Get()} *
                               frc::RobotController::GetInputVoltage(),
                           units::volt_t{_rightMotors.Get()} *
                               frc::RobotController::GetInputVoltage());
  _drivetrainSim.Update(20_ms);

  _leftEncoderSim.SetDistance(_drivetrainSim.GetLeftPosition().value());
  _leftEncoderSim.SetRate(_drivetrainSim.GetLeftVelocity().value());
  _rightEncoderSim.SetDistance(_drivetrainSim.GetRightPosition().value());
  _rightEncoderSim.SetRate(_drivetrainSim.GetRightVelocity().value());
  _gyroSim.SetAngle(-_drivetrainSim.GetHeading().Degrees());
}

void Drivetrain::ArcadeDrive(double thrust, double rotation) {
  _drive.ArcadeDrive(thrust, rotation);
}

// curvature
void Drivetrain::CurvatureDrive(double thrust, double rotation,
                                bool allowTurnInPlace) {
  _drive.CurvatureDrive(thrust, rotation, allowTurnInPlace);
}

void Drivetrain::TankDriveVolts(units::volt_t left, units::volt_t right) {
  _leftMotors.SetVoltage(left);
  _rightMotors.SetVoltage(right);
  _drive.Feed();
}

void Drivetrain::ResetEncoders() {
  _leftEncoder.Reset();
  _rightEncoder.Reset();
}

// returns currently drawn current
units::ampere_t Drivetrain::GetCurrentDraw() const {
  return _drivetrainSim.GetCurrentDraw();
}

double Drivetrain::GetAverageEncoderDistance() {
  return (_rightEncoder.GetDistance() + _leftEncoder.GetDistance()) / 2.0;
}

frc::Encoder& Drivetrain::GetLeftEncoder() {
  return _leftEncoder;
}

frc::Encoder& Drivetrain::GetRightEncoder() {
  return _rightEncoder;
}

units::degree_t Drivetrain::GetHeading() {
  return _gyro.GetRotation2d().Degrees();
}

double Drivetrain::GetTurnRate() {
  return -_gyro.GetRate();
}

frc::Pose2d Drivetrain::GetPose() {
  return _odometry.GetPose();
}
