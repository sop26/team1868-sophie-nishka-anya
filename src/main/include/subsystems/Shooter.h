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

  void Periodic() override;
  void SimulationPeriodic() override;

  void SetFlywheelOutput(double power);
  void SetFlywheelFeederOutput(double power);
  frc::ShuffleboardTab& GetPowerTab();
  double GetMaxPower();

 private:
  frc::Victor _flywheelMotor{FLYWHEEL_MOTOR_PORT};
  frc::Victor _flywheelFeederMotor{FLYWHEEL_PREP_MOTOR_PORT};

  frc::ShuffleboardTab& _powerTab;
  nt::NetworkTableEntry _maxPowerEntry;
  double _maxPower;
};
