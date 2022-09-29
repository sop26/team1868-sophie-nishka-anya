#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <frc/motorcontrol/Victor.h>

#include "PORTS.h"

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  void SetFlywheelOutput(double power);
  void SetFlywheelPrepOutput(double power);
  frc::ShuffleboardTab& GetPowerTab();
  double GetMaxPower();

 private:
  frc::Victor flyWheelMotor_{FLYWHEEL_MOTOR_PORT};
  frc::Victor flyWheelPrepMotor_{FLYWHEEL_PREP_MOTOR_PORT};

  frc::ShuffleboardTab& powerTab_;
  nt::NetworkTableEntry maxPowerEntry_;
  double maxPower_;
};