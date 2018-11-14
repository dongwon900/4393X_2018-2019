#include "main.h"
#include "drivetrain.h"

void drivetrain(){
  // handle the drivetrain
  int right = joystickGetAnalog(1, 2); // vertical axis on right joystick
  int left = joystickGetAnalog(1, 3); // vertical axis on left joystick

  motorSet(2, left);
  motorSet(8, left);
  motorSet(9, -right);
  motorSet(3, -right);
}
