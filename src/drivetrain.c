#include "main.h"
#include "drivetrain.h"

void drivetrainSet(int left, int right) {
  motorSet(2, left);
  motorSet(3, -right);
}

void drivetrain(){
  // handle the drivetrain
  int right = joystickGetAnalog(1, 2); // vertical axis on right joystick
  int left = joystickGetAnalog(1, 3); // vertical axis on left joystick
  drivetrainSet(left, right);
}
