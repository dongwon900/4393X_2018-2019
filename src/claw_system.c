#include "main.h"
#include "claw_system.h"

// up and down
void claw(bool up, bool down, int speed){
  if(up) motorSet(8, -speed);
  else if(down) motorSet(8, speed);
  else motorSet(8,0);
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
