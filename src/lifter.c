// clockwise is down yes
#include "main.h"
#include "lifter.h"

void lifter(){
  bool up = joystickGetDigital(1, 7, JOY_UP);
  bool down = joystickGetDigital(1, 7, JOY_DOWN);

  if(up && !down){
    motorSet(4, 90);
  }
  else if(!up && down){
    motorSet(4,-90);
  }
  else{
    motorSet(4,0);
  }
}
