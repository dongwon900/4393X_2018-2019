/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"


/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

void autonomous() {

  motorSet(6, 127);
  delay(1000);

  motorSet(6, -127);
  delay(1000);
  //
  // // Bit 1 (pin 12): (ON (left) <-> OFF (Right)
  // // Bit 2 (pin 11): (ON (Front) <-> OFF (Back))
  // // Bit 3 (pin 10): (ON (Auto on) <-> OFF (auto off))
  //
  // int x = 0;
  //
  // if (digitalRead(AUTO_BIT_ONE) == LOW) {
  //   x = x | 1; //0001
  // }
  //
  // if (digitalRead(AUTO_BIT_TWO) == LOW) {
  //   x = x | 2; //0010
  // }
  //
  // if (digitalRead(AUTO_BIT_THREE) == LOW) {
  //   x = x | 4; //0100
  // }
  //
  // lcdPrint(uart1, 1, (const char*) x);
  //
  // if (x >= 4) {
  //   // Left and Back
  //   if (x == 5) {
  //     // shoot to flip middle height flag
  //     motorSet(6, 127);
  //     delay(250);
  //     motorSet(6, 0);
  //   }
  //
  //   // Right and Front
  //   if (x == 6) {
  //     // shoot to flip middle height flag
  //     motorSet(6, 127);
  //     delay(1000);
  //     motorSet(6, 0);
  //
  //     // move to flip bottom flag
  //     motorSet(2, 127);
  //     motorSet(3, -127);
  //     delay(2250);
  //     motorStopAll();
  //
  //     // go back to starting position
  //     motorSet(2, -127);
  //     motorSet(3, 127);
  //     delay(2250);
  //     motorStopAll();
  //   }
  //
  //   // Left and Front
  //   if (x == 7) {
  //     // shoot to flip middle height flag
  //     motorSet(6, 127);
  //     delay(1000);
  //     motorSet(6, 0);
  //
  //     // move to flip bottom flag
  //     motorSet(2, 127);
  //     motorSet(3, -127);
  //     delay(2250);
  //     motorStopAll();
  //
  //     // go back to starting position
  //     motorSet(2, -127);
  //     motorSet(3, 127);
  //     delay(2250);
  //     motorStopAll();
  //   }
  //
  //   // Right and Back
  //   if (x == 4) {
  //     // shoot to flip middle height flag
  //     motorSet(6, 127);
  //     delay(250);
  //     motorSet(6, 0);
  //   }
  // }
}

//Justin's dank boy autonomous in the poor boy field area
//one high flag, one ground cap, one pole cap, alliance park
void autonomous1(){ //starting in the further alliance plartform (from flags)
  /*
  (face towards the flags)
  1.fire the launcher /
  2.lower the claw /
  3.turn 87 degrees counter clockwise (slightly off due to having to get a good angle to hit the flags) /
  4. turn intake on
  5.drive forward roughly 4 feet /
  6.(turn intake off)
  7.turn 90 degrees counter clockwise /
  8. drive forward 2 feet /
  9. raise claw /
  10. turn 90 degrees counter clockwise
  11. lower claw
  12.drive forward 1.2 feet
  13.turn 90 degrees clockwise
  14.drive backwards 1 foot
  15.raise claw
  16.raise arm
  17.drive forward 1.5 feet
  18.lower arm
  19.drive backwards 1 foot
  20.raise claw to stow it
  21.turn 180 degrees
  22.drive forward 2 feet (to the platform)
  23.climb the alliance platform
  */

  shoot(); //1
  timedMoveClaw(-127, 400); //2
  turn(-87); //3
  toggleIntake(); //4
  driveDistance(121); //5
  toggleIntake(); //6
  turn(-90); //7
  driveDistance(61); //8
  timedMoveClaw(127, 600); //9
  turn(90); //10
  timedMoveClaw(-127, 400); //1
  driveDistance(37); //12
  turn(90); //13
  driveDistance(-30); //14
  moveClaw(80); //15
  moveArm(100); //16
  driveDistance(46); //17
  timedMoveArm(-127, 250); //18
  driveDistance(-30); //19
  timedMoveClaw(127, 600); //20
  turn(180); //21
  driveDistance(61); //22
  timedDrive(127, 127, 1200); //23
}
