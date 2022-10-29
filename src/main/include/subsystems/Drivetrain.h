#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

#include "PORTS.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  void ArcadeDrive(double xSpeed, double zRotation, bool squareInputs = true);
  void CurvatureDrive(double xSpeed, double zRotation,
                      bool allowTurnInPlace = true);

 private:
  WPI_TalonSRX _leftPrimary{LEFT_DRIVE_PRIMARY};
  WPI_TalonSRX _rightPrimary{RIGHT_DRIVE_PRIMARY};
  WPI_TalonSRX _leftSecondary{LEFT_DRIVE_SECONDARY};
  WPI_TalonSRX _rightSecondary{RIGHT_DRIVE_SECONDARY};
  frc::MotorControllerGroup _rightMotorGroup{_rightPrimary, _rightSecondary};
  frc::MotorControllerGroup _leftMotorGroup{_leftPrimary, _leftSecondary};
  frc::DifferentialDrive _differentialDrive{_leftMotorGroup, _rightMotorGroup};

  // joy stick vals from sensor board

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};