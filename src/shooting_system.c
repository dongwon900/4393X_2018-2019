#include "main.h"

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

static bool isCocked = false; //MAKE THIS INITIALIZE TO THE STATE OF THE LIMIT SWITCH INSTEAD OF ALWAYS AT FALSE

void launcher() {
  bool launch = joystickGetDigital(1, 8, JOY_DOWN);
  // if limit switch not pressed down, continue reloading
  if (digitalRead(LIMIT_SWITCH) == HIGH) {
    motorSet(6, 127);
    isCocked = false;
  }
  // else, give control back to user for shooting
  else {
    if (isCocked == false) {
      //lcdSetText(uart1, 1, );
      motorSet(6, 127);
      delay(250);
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
