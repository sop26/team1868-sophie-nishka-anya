// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include "PORTS.h"
#include "ControlBoard.h"


class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();
  void SetFlywheelOutput(double power);
  void SetFlywheelPrepOutput(double power);
 private:
    frc::PWMVictorSPX _flywheelMotor{FLYWHEEL_MOTOR_PORT}, _flywheelPrepMotor{FLYWHEEL_PREP_MOTOR_PORT};
};
