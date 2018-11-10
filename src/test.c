#include <main.h>
#include <test.h>
#include <stdlib.h>

  int *ime_0;
  int *ime_1;

void test(){
  // // arm readings
  // printf("Arm: %d \n", analogRead(1));
  // // claw readings
  // printf("Claw: %d \n", analogRead(2));
  //
  // // left and right line tracker readings
  // printf("Left Line Tracker: %d \n", analogRead(3));
  // printf("Right Line Tracker: %d \n", analogRead(4));
  //
  // // left and right encoder readings
  // imeGet(0,ime_0);
  // imeGet(0,ime_1);
  // printf("left encoder count: %d, right encoder count: %d \n", *ime_0, *ime_1);
  //
  // delay(750);
  // system("clear");
};

// int menu_state = 0;

// void inDiagnostics(){
//   // 2-state FSM
//   if(lcdReadButtons(uart1) == 2){
//     if(inDiagnostics_state == false){
//       inDiagnostics_state = true;
//     }
//     else{
//       inDiagnostics_state = false;
//     }
//   }
// }

// // function that outputs diagnostics information onto the lcd
// void test(){
//   // read button
//   // LCD_BTN_LEFT 1
//   // LCD_BTN_CENTER 2
//   // LCD_BTN_RIGHT 4
//
//   // change menu states according to button presses
//   // "circular" FSM
//
//
//
//   // menu 0
//   if(menu_state == 0){
//     // display encoder stats
//
//   }
//   // menu 1
//   else if(menu_state == 1){
//     // display potentiometer stats
//
//   }
//   // output the diagnostics
//   else if(menu_state == 1){
//     // display memes
//
//   }
//
// }
