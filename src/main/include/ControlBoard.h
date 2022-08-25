#include <frc2/command/SubsystemBase.h>
#include "PORTS.h"



class ControlBoard: public frc2::SystemBase {
 public:
  ControlBoard();
  double GetJoystickValue();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */


 private:

    
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};