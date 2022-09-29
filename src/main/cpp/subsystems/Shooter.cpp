#include "subsystems/Shooter.h"
#include "Ports.h"

Shooter::Shooter() : powerTab_(frc::Shuffleboard::GetTab("Set Max Power")) {
  flyWheelMotor_.SetInverted(true);

  maxPowerEntry_ = GetPowerTab().Add("Max Drive Output", 0.5).GetEntry();
}

void Shooter::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Shooter::SimulationPeriodic() {}

double Shooter::GetMaxPower() {
  maxPower_ = maxPowerEntry_.GetDouble(0.5);
  return maxPower_;
}

void Shooter::SetFlywheelOutput(double power) {
  flyWheelMotor_.Set(power);
}

void Shooter::SetFlywheelPrepOutput(double power) {
  flyWheelPrepMotor_.Set(power);
}

frc::ShuffleboardTab& Shooter::GetPowerTab() {
  return powerTab_;
}