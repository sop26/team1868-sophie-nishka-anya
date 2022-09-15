// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include <rev/CANSparkMax.h>

Drivetrain::Drivetrain() {
  // Implementation of subsystem constructor goes here.
}

void Drivetrain::ArcadeDrive(double thrust, double rotation) {
  _drive.ArcadeDrive(thrust, rotation);
}

// curvature
void Drivetrain::CurvatureDrive(double thrust, double rotation,
                                bool allowTurnInPlace) {
  _drive.CurvatureDrive(thrust, rotation, allowTurnInPlace);
}
