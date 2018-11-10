#include <main.h>
#include <test.h>
#include <stdlib.h>

  int *ime_0;
  int *ime_1;

void test(){
  // arm readings
  print("Arm: ");
  print((const char*) analogRead(1));
  print("\n");
  // claw readings
  print("Claw: ");
  print((const char*) analogRead(2));
  print("\n");

  // left and right line tracker readings
  print("left linetracker: ");
  print((const char*) analogRead(3));
  print("\n");
  print("right linetracker: ");
  print((const char*) analogRead(4));
  print("\n");

  // left and right encoder readings
  imeGet(0,ime_0);
  imeGet(0,ime_1);

  print("left encoder: ");
  print((const char*) *ime_0);
  print("\n");
  print("right encoder: ");
  print((const char*) *ime_1);
  print("\n");

  //print("distance from wall: ");
  //print((const char*) ultrasonicGet(sonar));
  //print("\n");

  delay(250);
};
