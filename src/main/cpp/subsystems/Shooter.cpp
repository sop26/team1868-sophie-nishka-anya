#include "subsystems/Shooter.h"
#include "Ports.h"

Shooter::Shooter() : _powerTab(frc::Shuffleboard::GetTab("Set Max Power")) {
  _flyWheelMotor.SetInverted(false);

  _maxPowerEntry = GetPowerTab().Add("Max Drive Output", 0.5).GetEntry();
}

void Shooter::Periodic() {}

void Shooter::SimulationPeriodic() {}

double Shooter::GetMaxPower() {
  _maxPower = _maxPowerEntry.GetDouble(0.5);
  return _maxPower;
}

void Shooter::SetFlywheelOutput(double power) {
  _flyWheelMotor.Set(power);
}

void Shooter::SetFlywheelPrepOutput(double power) {
  _flyWheelPrepMotor.Set(power);
}

frc::ShuffleboardTab& Shooter::GetPowerTab() {
  return _powerTab;
}
