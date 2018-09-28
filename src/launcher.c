#include "main.h"
#include "launcher.h"

static bool isCocked = false;

void launcher() {
  bool launch = joystickGetDigital(1, 6, JOY_DOWN);
  // if limit switch not pressed down, continue reloading
  if (digitalRead(LIMIT_SWITCH) == HIGH) {
    motorSet(6, 127);
    isCocked = false;
  }
  // else, give control back to user for shooting
  else {
    if (isCocked == false) {
      motorSet(6, 127);
      delay(750);
      isCocked = true;
      motorSet(6, 0);
    }

    if (launch) {
      motorSet(6, 127);
    } else {
      motorSet(6,0);
    }
  }
}
