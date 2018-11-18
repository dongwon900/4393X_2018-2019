#include "main.h"
#include "drivetrain.h"

void leftMotors(int speed) {
  motorSet(2, speed);
  motorSet(8, speed);
}

void rightMotors(int speed) {
  motorSet(3, -speed);
  motorSet(9, -speed);
}

void drive(int leftSpeed, int rightSpeed)
{
  leftMotors(leftSpeed);
  rightMotors(rightSpeed);
}

void drivetrain(){
  // handle the drivetrain
  int right = joystickGetAnalog(1, 2); // vertical axis on right joystick
  int left = joystickGetAnalog(1, 3); // vertical axis on left joystick

  drive(left, right);
}

//ALL CODE RELATING TO IME FUNCTIONALITY AND USING THE IMES
//EXPERIMENTAL DONT EXPECT ANYTHING TO WORK PERFECTLY OR AT ALL
//CURRENTLY DOES NOT ACCOUNT FOR ERROR WITHIN THE IME READINGS THEMSELVES
void resetAllIME(int IMECount){
  for(int i = 0; i < IMECount; i++){
    imeReset(i);
  }
}

void updateAllIME(int* leftValue, int* rightValue){
  imeGet(0, leftValue);
  imeGet(1, rightValue);
}

void updateDistances(double *rightDistance, double *leftDistance, int leftDriveIME, int rightDriveIME){
  const double wheelDiameter = 4 * 2.54; //omni diameter is 4 inhes and convert to centimeters
  const double wheelCircumference = wheelDiameter * 3.1415;

  *leftDistance = leftDriveIME/627.2 * wheelCircumference;
  *rightDistance = rightDriveIME/627.2 * wheelCircumference;
}

void driveDistance(int distance){ //distance is in inches
  resetAllIME(2);

  int leftDriveCount = 0;
  int rightDriveCount = 0;

  imeGet(0, &leftDriveCount);
  imeGet(1, &rightDriveCount); //one rotation of the shaft is equal to 627.2 ccount

//this is the same as update distances but it initilizes the variables (shrug emoji)
  const double wheelDiameter = 4 * 2.54; //omni diameter is 4 inhes and convert to centimeters
  const double wheelCircumference = wheelDiameter * 3.1415;
  double distanceTravelledLeft = leftDriveCount/627.2 * wheelCircumference;
  double distanceTravelledRight = rightDriveCount/627.2 * wheelCircumference;

bool completedMove = false;

while(!completedMove){

  if(distanceTravelledLeft == distanceTravelledRight && distanceTravelledLeft < distance){
    while(distanceTravelledLeft < distance && distanceTravelledRight < distance){
      drive(127, 127);
      updateAllIME(&leftDriveCount, &rightDriveCount);
      updateDistances(&distanceTravelledLeft, &distanceTravelledRight, leftDriveCount, rightDriveCount);
    }
    drive(0, 0);
    updateAllIME(&leftDriveCount, &rightDriveCount);
    updateDistances(&distanceTravelledLeft, &distanceTravelledRight, leftDriveCount, rightDriveCount);
  }
  else if(distanceTravelledLeft < distance && distanceTravelledRight < distance){
    while (distanceTravelledLeft < distanceTravelledRight && distanceTravelledLeft < distance && distanceTravelledRight < distance){
      drive(127, 100);
      updateAllIME(&leftDriveCount, &rightDriveCount);
      updateDistances(&distanceTravelledLeft, &distanceTravelledRight, leftDriveCount, rightDriveCount);
    }
    drive(0, 0);
    updateAllIME(&leftDriveCount, &rightDriveCount);
    updateDistances(&distanceTravelledLeft, &distanceTravelledRight, leftDriveCount, rightDriveCount);
    while(distanceTravelledLeft < distanceTravelledRight && distanceTravelledLeft < distance && distanceTravelledRight < distance){
      drive(100, 127);
      updateAllIME(&leftDriveCount, &rightDriveCount);
      updateDistances(&distanceTravelledLeft, &distanceTravelledRight, leftDriveCount, rightDriveCount);
    }
    drive(0, 0);
    updateAllIME(&leftDriveCount, &rightDriveCount);
    updateDistances(&distanceTravelledLeft, &distanceTravelledRight, leftDriveCount, rightDriveCount);
  }
  else if(distanceTravelledLeft >= distance || distanceTravelledRight >= distance){
    completedMove = true;
  }
}
}

//SWITCH TO USING A GYRO  TO TURN TO PREVENT MOTOR SLIPPAGE
void updateDegrees(int leftIMECount, int rightIMECount, double* leftDegrees, double* rightDegrees){
  *leftDegrees = leftIMECount / 3;
  *rightDegrees = rightIMECount / 3;
}

void turn(int degrees){ //in order for this to be entirely correct the ratio of
  resetAllIME(2);
  int leftDriveCount = 0;
  int rightDriveCount = 0;
  imeGet(0, &leftDriveCount);
  imeGet(1, &rightDriveCount);
  //gonna use the value of 3 ticks on both motors to be one degree of rotation and this gives 270 ticks for a 90 degree turn
  double degreesMovedLeft;
  double degreesMovedRight;
  updateDegrees(leftDriveCount, rightDriveCount, &degreesMovedLeft, &degreesMovedRight);

bool turnCompleted = false;

while(!turnCompleted){
  while(degreesMovedLeft < degrees && degreesMovedRight < degrees){
    drive(127, -127);
    updateAllIME(&leftDriveCount, &rightDriveCount);
    updateDegrees(leftDriveCount, rightDriveCount, &degreesMovedLeft, &degreesMovedRight);
  }
  drive(0,0);
  updateAllIME(&leftDriveCount, &rightDriveCount);
  updateDegrees(leftDriveCount, rightDriveCount, &degreesMovedLeft, &degreesMovedRight);
  if(degreesMovedLeft < degrees){
  while(degreesMovedLeft < degrees){
    drive(127, 0);
    updateAllIME(&leftDriveCount, &rightDriveCount);
    updateDegrees(leftDriveCount, rightDriveCount, &degreesMovedLeft, &degreesMovedRight);
  }
  drive(0,0);
  updateAllIME(&leftDriveCount, &rightDriveCount);
  updateDegrees(leftDriveCount, rightDriveCount, &degreesMovedLeft, &degreesMovedRight);
}
else{
  while(degreesMovedRight < degrees){
    drive(0,-127);
    updateAllIME(&leftDriveCount, &rightDriveCount);
    updateDegrees(leftDriveCount, rightDriveCount, &degreesMovedLeft, &degreesMovedRight);
  }
  drive(0,0);
  updateAllIME(&leftDriveCount, &rightDriveCount);
  updateDegrees(leftDriveCount, rightDriveCount, &degreesMovedLeft, &degreesMovedRight);
}
  drive(0,0);
  turnCompleted = true;
}
}
