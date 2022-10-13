// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/system/plant/DCMotor.h>
#include <frc/system/plant/LinearSystemId.h>
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <wpi/numbers>

constexpr double LEFT_TRIGGER_BARRIER = 0.5;
constexpr double RIGHT_TRIGGER_BARRIER = 0.5;

// need to change
extern const frc::LinearSystem<2, 2, 2> DRIVETRAIN_PLANT;
constexpr auto TRACK_WIDTH = 0.0;
constexpr auto DRIVETRAIN_GEARBOX = frc::DCMotor::CIM(2);
constexpr auto DRIVETRAIN_GEARING = 0.0;
constexpr auto WHEEL_DIAMETER = 0.0_in;
