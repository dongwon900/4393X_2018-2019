#include <main.h>
#include <test.h>

int menu_state = 0;

void inDiagnostics(){
  // 2-state FSM
  if(lcdReadButtons(uart1) == 2){
    if(inDiagnostics_state == false){
      inDiagnostics_state = true;
    }
    else{
      inDiagnostics_state = false;
    }
  }
}

// function that outputs diagnostics information onto the lcd
void test(){
  // read button
  // LCD_BTN_LEFT 1
  // LCD_BTN_CENTER 2
  // LCD_BTN_RIGHT 4

  // change menu states according to button presses
  // "circular" FSM



  // menu 0
  if(menu_state == 0){
    // display encoder stats
    
  }
  // menu 1
  else if(menu_state == 1){
    // display potentiometer stats

  }
  // output the diagnostics
  else if(menu_state == 1){
    // display memes

  }

}
