#include "main.h"
#include "balllift.h"

//static bool toggleLift = false;

void balllift(){
  // handle the drivetrain
  bool lift = joystickGetDigital(1, 8, JOY_UP);

  //if(lift){
  //  toggleLift = true;
  //}

  //if(lift && toggleLift){
  //  toggleLift = false;
//  }


  // if button pressed set motor
  if(lift){
    motorSet(5, -127);
  }
  // else stop motor
  else{
    motorSet(5,0);
  }

}
