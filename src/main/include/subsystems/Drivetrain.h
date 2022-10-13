// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "ControlBoard.h"
#include <frc/Encoder.h>
#include <frc/ADXRS450_Gyro.h>
// simulation
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/simulation/DifferentialDrivetrainSim.h>
#include <frc/simulation/EncoderSim.h>
#include <frc/simulation/ADXRS450_GyroSim.h>
#include <frc/smartdashboard/Field2d.h>
#include "CONSTANTS.h"
#include <rev/CANSparkMax.h>
#include <frc/RobotController.h>

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  void ArcadeDrive(double thrust, double rotation);
  void CurvatureDrive(double thrust, double rotation, bool allowTurnInPlace);
  void SimulationPeriodic();
  void Periodic();
  void ResetEncoders();
  void TankDriveVolts(units::volt_t left, units::volt_t right);
  double GetAverageEncoderDistance();
  frc::Encoder& GetLeftEncoder();
  frc::Encoder& GetRightEncoder();
  units::ampere_t GetCurrentDraw() const;
  units::degree_t GetHeading();
  double GetTurnRate();
  frc::Pose2d GetPose();

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

  frc::Encoder _rightEncoder{RIGHT_ENCODER_PORT_A, RIGHT_ENCODER_PORT_B};
  frc::Encoder _leftEncoder{LEFT_ENCODER_PORT_A, LEFT_ENCODER_PORT_B};

  frc::ADXRS450_Gyro _gyro;

  frc::DifferentialDriveOdometry _odometry{_gyro.GetRotation2d()};
  frc::sim::DifferentialDrivetrainSim _drivetrainSim{
      DRIVETRAIN_PLANT, TRACK_WIDTH, DRIVETRAIN_GEARBOX, DRIVETRAIN_GEARING,
      WHEEL_DIAMETER / 2};  // need to change

  frc::sim::EncoderSim _leftEncoderSim{_leftEncoder};
  frc::sim::EncoderSim _rightEncoderSim{_rightEncoder};
  frc::sim::ADXRS450_GyroSim _gyroSim{_gyro};

  // The Field2d class shows the field in the sim GUI.
  frc::Field2d _fieldSim;
};
