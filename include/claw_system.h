#include "main.h"

void claw(bool up, bool down, int speed);
void arm(bool up, bool down, int speed);
// void auto_cap(int height);
void adjustDistance(int requiredDistance);
void claw_system(int clawspeed, int armspeed);
void updateSonar(int *distance);
