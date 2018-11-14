#include "main.h"
#include "shooting_system.h"

void balllift(int speed){
  // handle the drivetrain
  bool lift = joystickGetDigital(1, 8, JOY_UP);

  // if button pressed set motor
  if(lift){
    motorSet(5, -speed);
  }
  // else stop motor
  else{
    motorSet(5,0);
  }

}

static bool isCocked = false;

void launcher(int speed){
  bool launch = joystickGetDigital(1, 8, JOY_RIGHT);
  // if limit switch not pressed down, continue reloading
  if (digitalRead(LIMIT_SWITCH) == HIGH) {
    motorSet(6, speed);
    isCocked = false;
  }
  // else, give control back to user for shooting
  else {
    if (isCocked == false) {
      //lcdSetText(uart1, 1, );
      motorSet(6, speed);
      delay(350);
      isCocked = true;
      motorSet(6, 0);
    }

    if (launch) {
      motorSet(6, speed);
    } else {
      motorSet(6,0);
    }
  }
}

void disarm(){
	motorSet(6, -127);
	delay(1300);
	motorSet(6, 0);
}

// checks for disarm button input
void checkdisarm(){
  // if button pressed
  if(joystickGetDigital(1, 7, JOY_RIGHT)){
      disarm();
  }
}

void shooting_system(int ballspeed, int launcherspeed){
  balllift(ballspeed);
  launcher(launcherspeed);
}
