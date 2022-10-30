#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  _drivetrain.SetDefaultCommand(_driveCommand);
  _shooter.SetDefaultCommand(_prepShotCommand);
  _controlBoard._flywheelButton.WhenHeld(_shootCommand);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return nullptr;
}
