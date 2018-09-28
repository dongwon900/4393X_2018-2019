#include "main.h"
#include "clawlift.h"

void clawlift(){
  bool up = joystickGetDigital(1, 8, JOY_UP);
  bool down = joystickGetDigital(1, 8, JOY_DOWN);

  int potreading = analogRead(1);

  while(potreading >= 75 && potreading <= 103){
    if (up) motorSet(8, -127);
    else if (down) motorSet(8, 127);
    else motorSet(8, 0);
  }
}
