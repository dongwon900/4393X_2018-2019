#include "main.h"
#include "clawlift.h"

void clawlift(){
  bool up = joystickGetDigital(1, 8, JOY_UP);
  bool down = joystickGetDigital(1, 8, JOY_DOWN);

  if (up) motorSet(7, -50);
  else if (down) motorSet(7, 50);
  else motorSet(7, 0);
}
