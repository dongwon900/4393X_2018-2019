#include "main.h"

void claw(bool up, bool down, int speed);
void arm(bool up, bool down, int speed);
// void auto_cap(int height);
void adjustDistance(int requiredDistance); //takes a distance and drives linerarly towards that distance from the objet infront of it

void claw_system(int clawspeed, int armspeed);
