#include "main.h"
#include "balllift.h"

void balllift(){
  // handle the drivetrain
  bool lift = joystickGetDigital(1, 6, JOY_UP);

  // if button pressed set motor
  if(lift){
    motorSet(5, -127);
  }
  // else stop motor
  else{
    motorSet(5,0);
  }

}
