#include "main.h"
#include "claw_system.h"

// incomplete, no spinning claw
void claw(){
  bool open = joystickGetDigital(1, 5, JOY_UP);
  bool close = joystickGetDigital(1, 5, JOY_DOWN);

  if(open){
    return;
  }
  else if(close){
    return;
  }
}

void arm(int speed){
  bool up = joystickGetDigital(1, 8, JOY_UP);
  bool down = joystickGetDigital(1, 8, JOY_DOWN);

  if (up) motorSet(7, -speed);
  else if (down) motorSet(7, speed);
  else motorSet(7, 0);
}
