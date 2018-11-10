#include "main.h"

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

static bool isCocked = false; //MAKE THIS INITIALIZE TO THE STATE OF THE LIMIT SWITCH INSTEAD OF ALWAYS AT FALSE

void launcher(int speed){
  bool launch = joystickGetDigital(1, 8, JOY_DOWN);
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
      delay(250);
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

static bool disarmed = false;

void disarm(){
  // if the launcher is cocked
	if(isCocked == true){
		motorSet(6, -127);
		delay(1000);
		motorSet(6, 0);
	}
  // it is now disarmed
  disarmed = true;
}

// checks for disarm button input
void checkdisarm(){
  // if button pressed
  if(joystickGetDigital(1, 7, JOY_RIGHT) == true){
    // and if robot armed
    if(disarmed == false){
      // change robot state to disarmed
      disarm();
    }
    // if robot disarmed
    else{
      // change robot state to armed
      disarmed = false;
    }
  }
}

void shooting_system(int ballspeed, int launcherspeed){
  balllift(ballspeed);
  launcher(launcherspeed);
}
