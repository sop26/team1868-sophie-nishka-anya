#pragma once

// Drive Talon IDs
static const int LEFT_DRIVE_PRIMARY = 0;
static const int RIGHT_DRIVE_PRIMARY = 1;
static const int LEFT_DRIVE_SECONDARY = 2;
static const int RIGHT_DRIVE_SECONDARY = 3;

// Joystick USB Ports
static const int LEFT_JOY_USB_PORT = 0;
static const int RIGHT_JOY_USB_PORT = 1;
static const int OPERATOR_JOY_USB_PORT = 3;
static const int OPERATOR_JOY_B_USB_PORT = 2;

static const int FLYWHEEL_BUTTON_PORT = 4;
static const int FLYWHEEL_PREP_BUTTON_PORT = 3;

static const int FLYWHEEL_MOTOR_PORT = 8;
static const int FLYWHEEL_PREP_MOTOR_PORT = 5;

// LEDS
// change this to light up more or less LEDs! Max: 38
constexpr int LED_LENGTH = 38;
constexpr int LED_PORT = 0;   // may be incorrect. check!
constexpr int LED_SAT = 200;  // do not change
constexpr int LED_VAL = 150;  // do not change
