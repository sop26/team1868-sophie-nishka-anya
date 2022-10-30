#include "subsystems/Shooter.h"
#include "Ports.h"

Shooter::Shooter() : _powerTab(frc::Shuffleboard::GetTab("Set Max Power")) {
  _flywheelMotor.SetInverted(false);

  _maxPowerEntry = GetPowerTab().Add("Max Drive Output", 0.5).GetEntry();
}

void Shooter::Periodic() {}

void Shooter::SimulationPeriodic() {}

double Shooter::GetMaxPower() {
  _maxPower = _maxPowerEntry.GetDouble(0.5);
  return _maxPower;
}

void Shooter::SetFlywheelOutput(double power) {
  _flywheelMotor.Set(power);
}

void Shooter::SetFlywheelFeederOutput(double power) {
  _flywheelFeederMotor.Set(power);
}

frc::ShuffleboardTab& Shooter::GetPowerTab() {
  return _powerTab;
}
