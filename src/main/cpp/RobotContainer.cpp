#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  _drivetrain.SetDefaultCommand(_driveCommand);
  _controlBoard._prepFlywheelButton.WhenPressed(_shootCommand);
  _controlBoard._flywheelButton.WhenPressed(_shootCommand);
}

void RobotContainer::UpdateLEDs() {
  _controlBoard.GetPrepFlywheelDesired() ? _ledController.UpdateShooting()
                                         : _ledController.Update();
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return nullptr;
}
