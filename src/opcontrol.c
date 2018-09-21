#include "main.h"
#include "drivetrain.h"
#include "balllift.h"
#include "claw.h"
#include "clawlift.h"
#include "launcher.h"
#include "lifter.h"

// the operatorControl loop
void operatorControl() {
	while (1) {
    drivetrain();
    balllift();
		claw();
		clawlift();
		launcher();
		lifter();
	}
}
