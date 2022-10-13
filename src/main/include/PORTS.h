// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
// Joysticks
// constexpr int LEFT_JOY_USB_PORT = 1;
// constexpr int RIGHT_JOY_USB_PORT = 0;
// constexpr int OPERATOR_JOY_USB_PORT = 2;  // TODO: fix
// constexpr int OPERATOR_JOY_B_USB_PORT = 3;

constexpr int XBOX_DRIVER_PORT = 0;
constexpr int LEFT_JOYSTICK_DRIVER_PORT = 1;
constexpr int RIGHT_JOYSTICK_DRIVER_PORT = 0;

constexpr int LEFT_PRIMARY_ID = 0;
constexpr int LEFT_SECONDARY_ID = 2;
constexpr int RIGHT_PRIMARY_ID = 1;
constexpr int RIGHT_SECONDARY_ID = 3;

// shooter
constexpr int FLYWHEEL_MOTOR_PORT = 8;
constexpr int FLYWHEEL_PREP_MOTOR_PORT = 5;
// constexpr int FLYWHEEL_JOY_X_PORT = 2;
constexpr int FLYWHEEL_BUTTON_PORT = 3;
constexpr int FLYWHEEL_PREP_BUTTON_PORT = 4;
constexpr int OPERATOR_JOY_B_USB_PORT = 2;

// encoders n
constexpr int RIGHT_ENCODER_PORT_A = 0;
constexpr int RIGHT_ENCODER_PORT_B = 0;
constexpr int LEFT_ENCODER_PORT_A = 0;
constexpr int LEFT_ENCODER_PORT_B = 0;
