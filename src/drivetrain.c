#include "main.h"
#include "drivetrain.h"

void drivetrain(){
  // handle the drivetrain
  int right = joystickGetAnalog(1, 2); // vertical axis on right joystick
  int left = joystickGetAnalog(1, 3); // vertical axis on left joystick

  motorSet(2, left);
  motorSet(8, left);
  motorSet(9, -right);
  motorSet(3, -right);
}

void driveDistance(int distance){
  int* leftDriveCount = 0;
  int* rightDriveCount = 0;

  imeGet(0, leftDriveCount);
  imeGet(1, rightDriveCount); //one rotation of the shaft is equal to 627.2 ccount

  double wheelDiameter = 4 * 2.54; //omni diameter is 4 inhes and convert to centimeters
  double wheelCircumference = wheelDiameter * 3.1415;

  double* lDrive = (double*) leftDriveCount;
  double* rDrive = (double*) rightDriveCount; //casts the ints to double*

  //double* distaneTravelledLeft =  lDrive / wheelCircumference;
  //double* distanceTravelledRight =  rDrive / wheelCircumference; //wtf how why no work

}
