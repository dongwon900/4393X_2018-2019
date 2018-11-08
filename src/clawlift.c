#include "main.h"
#include "clawlift.h"

void clawlift(){
  bool up = joystickGetDigital(1, 6, JOY_UP);
  bool down = joystickGetDigital(1, 6, JOY_DOWN);

  //int potreading = analogRead(1);

  //while(potreading >= 0 && potreading <= 200){
    if (up) motorSet(7, 127);
    else if (down) motorSet(7, -127);
    else motorSet(7, 0);
  //}
}
