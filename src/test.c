#include <main.h>
#include <test.h>

  int *ime_0;
  int *ime_1;

void test(){
  // arm readings
  print("\nArm: ");
  print((const char*) analogRead(1));
  // claw readings
  print("\nClaw: ");
  print((const char*) analogRead(2));

  // left line tracker readings
  print("\nLeft_linetracker: ");
  print((const char*) analogRead(3));
  // right line tracker readings
  print("\nRight_linetracker: ");
  print((const char*) analogRead(4));

  // left and right encoder readings
  imeGet(0,ime_0);
  imeGet(0,ime_1);
  printf("left encoder count: %d, right encoder count: %d", *ime_0, *ime_1);

  // std::stringstream ss;
  //
  // ss << "left encoder count: " << *ime_0 << " blarg";

  // printf(ss.str().c_str());

  // ultrasonic sensor readings
  //print();

};
