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

void resetAllIME(int IMECount){
  for(int i = 0; i < IMECount; i++){
    imeReset(i);
  }
}

void drivetrain(){
  // handle the drivetrain
  int right = joystickGetAnalog(1, 2); // vertical axis on right joystick
  int left = joystickGetAnalog(1, 3); // vertical axis on left joystick

  drive(left, right);
}

void driveDistance(int distance){
  resetAllIME(2);

  int leftDriveCount = 0;
  int rightDriveCount = 0;

  imeGet(0, &leftDriveCount);
  imeGet(1, &rightDriveCount); //one rotation of the shaft is equal to 627.2 ccount

  const double wheelDiameter = 4 * 2.54; //omni diameter is 4 inhes and convert to centimeters
  const double wheelCircumference = wheelDiameter * 3.1415;

  double distanceTravelledLeft = leftDriveCount/627.2 * wheelCircumference;
  double distanceTravelledRight = rightDriveCount/627.2 * wheelCircumference;

}
