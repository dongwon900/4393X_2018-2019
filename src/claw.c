#include "main.h"
#include "claw.h"

void claw(){
  bool up = joystickGetDigital(1, 5, JOY_UP);
  bool down = joystickGetDigital(1, 5, JOY_DOWN);

  //int clawPotValue = analogRead(2);
  if(up && !down){
    motorSet(10, -90);
  }
  else if(!up && down){
    motorSet(10, 90);
  }
  else{
    motorSet(10,0);
  }
}
