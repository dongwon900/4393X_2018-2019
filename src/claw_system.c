#include "main.h"
#include "claw_system.h"

// up and down
void claw(bool up, bool down, int speed){
  if(up) motorSet(10, -speed);
  else if(down) motorSet(10, speed);
  else motorSet(10,0);
}

void arm(bool up, bool down, int speed) {
  if (up) motorSet(7, speed);
  else if (down) motorSet(7, -speed);
  else motorSet(7, 0);
}

// handles the input
void claw_system(int clawspeed, int armspeed){
  claw(joystickGetDigital(1, 5, JOY_UP), joystickGetDigital(1, 5, JOY_DOWN), clawspeed);
  arm(joystickGetDigital(1, 6, JOY_UP), joystickGetDigital(1, 6, JOY_DOWN), armspeed);
}

void adjustDistance(int requiredDistance){
  int distanceFromWall = ultrasonicGet(sonar); //get the current distance
  //int requiredDistane = 12; //arbitrary distance to cover
  int fudgeFactor = 1;
  //bool distanceUpdated = false;
  lcdPrint(uart1, 1, "Distance: %d", distanceFromWall);
  while(distanceFromWall > requiredDistance + fudgeFactor){
    motorSet(2, 30);
    motorSet(3, -30);
    motorSet(8, 30);
    motorSet(9, -30); //drives robot forward
    delay(20);
    distanceFromWall = ultrasonicGet(sonar);
    lcdPrint(uart1, 1, "Distance: %d", distanceFromWall);
    lcdSetText(uart1, 2, "Forward state");
  }
  while(distanceFromWall < requiredDistance - fudgeFactor){
    motorSet(2, -30);
    motorSet(3, 30);
    motorSet(8, -30);
    motorSet(9, 30); //drives robot bakward
    delay(10);
    distanceFromWall = ultrasonicGet(sonar);
    lcdPrint(uart1, 1, "Distance: %d", distanceFromWall);
    lcdSetText(uart1, 2, "Reverse state");
  }
  motorSet(2, 0);
  motorSet(3, 0);
  motorSet(8, 0);
  motorSet(9, 0); //sets back to stopped
}

// int arm_level = 0;
// double arm_pot_values[3] = {2000, 2500, 3000}; // insert pot val 1, 2, 3
//
// void arm(bool up, bool down, int speed) {
//   //if (up) motorSet(7, -speed);
//   //else if (down) motorSet(7, speed);
//   //else motorSet(7, 0);
//
//   if (up) {
//     if (arm_level < 2) {
//       arm_level++;
//       while (analogRead(2) < arm_pot_values[2] - tolerance) {
//         motorSet(7, -speed);
//       }
//       motorSet(7, 0);
//     }
//   }
//
//   if (down) {
//     if (arm_level > 1) {
//       arm_level--;
//       while (analogRead(2) > arm_pot_values[0] + tolerance) {
//         motorSet(7, speed);
//       }
//       motorSet(7, 0);
//     }
//   }
// }
