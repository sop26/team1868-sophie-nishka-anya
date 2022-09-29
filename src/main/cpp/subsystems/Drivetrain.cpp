#include "subsystems/Drivetrain.h"
#include "Ports.h"

Drivetrain::Drivetrain() {
  _leftMotorGroup.SetInverted(true);
}

void Drivetrain::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Drivetrain::ArcadeDrive(double thrust, double rotate, bool squareInputs) {
  _differentialDrive.ArcadeDrive(thrust, rotate, squareInputs);
}

void Drivetrain::CurvatureDrive(double xSpeed, double zRotation,
                                bool allowTurnInPlace) {
  _differentialDrive.CurvatureDrive(xSpeed, zRotation, allowTurnInPlace);
}

void Drivetrain::SimulationPeriodic() {}