#include "main.h"
#include "claw.h"

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
