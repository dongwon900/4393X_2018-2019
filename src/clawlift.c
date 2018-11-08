#include "main.h"
#include "clawlift.h"

void clawlift(){
<<<<<<< HEAD
  bool up = joystickGetDigital(1, 6, JOY_UP);
  bool down = joystickGetDigital(1, 6, JOY_DOWN);

  //int potreading = analogRead(1);

  //while(potreading >= 0 && potreading <= 200){
    if (up) motorSet(7, 127);
    else if (down) motorSet(7, -127);
    else motorSet(7, 0);
  //}
=======
  bool up = joystickGetDigital(1, 8, JOY_UP);
  bool down = joystickGetDigital(1, 8, JOY_DOWN);

  if (up) motorSet(7, -50);
  else if (down) motorSet(7, 50);
  else motorSet(7, 0);
>>>>>>> f9372414b591d2ec8d3e35186259a0ee16446ae0
}
