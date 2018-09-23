#include "main.h"
#include "launcher.h"

void launcher(){
  bool launch = joystickGetDigital(1, 6, JOY_DOWN);
  if(launch){
    motorSet(6, 127);
  }
  else{
    motorSet(6,0);
  }
}
