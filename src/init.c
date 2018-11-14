/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
  /*
   * Runs user initialization code. This function will be started in its own task with the default
   * priority and stack size once when the robot is starting up. It is possible that the VEXnet
   * communication link may not be fully established at this time, so reading from the VEX
   * Joystick may fail.
   *
   * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
   * variables, and IMEs.
   *
   * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
   * will not start. An autonomous mode selection menu like the pre_auton() in other environments
   * can be implemented in this task if desired.
   */

  // arm pot
  pinMode(1, INPUT_ANALOG);
  // claw
  pinMode(2, INPUT_ANALOG);
  // left line tracker
  pinMode(3, INPUT_ANALOG);
  // right line tracker
  pinMode(4, INPUT_ANALOG);

  // launcher limit switch
  pinMode(LIMIT_SWITCH, INPUT);

  // auto limit switches
  pinMode(AUTO_BIT_ONE, INPUT);
  pinMode(AUTO_BIT_TWO, INPUT);
  pinMode(AUTO_BIT_THREE, INPUT);
}

 int initializeAutoMode() {
   int x = 0;
   if (digitalRead(AUTO_BIT_ONE) == LOW) {
     x = x | 1; //0001
   }

   if (digitalRead(AUTO_BIT_TWO) == LOW) {
     x = x | 2; //0010
   }

   if (digitalRead(AUTO_BIT_THREE) == LOW) {
     x = x | 4; //0100
   }

   return x - 4;
 }

void initialize() {
  // initialize lcds
  lcdInit(uart1);
  lcdClear(uart1);

  const char *a[3];
  a[0] = "Back Right";
  a[1] = "Back Left";
  a[2] = "Front Right";
  a[3] = "Front Left";

  lcdPrint(uart1, 1, a[initializeAutoMode()]);
  print(a[initializeAutoMode()]);

  // ultrasonic in, out
  sonar = ultrasonicInit(3, 2);

  // initialize encoders
  int IMEcount = imeInitializeAll();
  if(IMEcount != 2){
    //makes sure only 2 IMEs are registered
  }
  else{
    for(int i = 0; i < IMEcount; i++){ //reset all encoders regardless of the ammount
      imeReset(i);
    }
  }

}
