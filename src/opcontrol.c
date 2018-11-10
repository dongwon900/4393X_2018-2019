#include "main.h"
#include "drivetrain.h"
#include "claw_system.h"
#include "shooting_system.h"
#include "plant_system.h"
#include "test.h"

// the operatorControl
void operatorControl() {
	while (1) {
		// checks for disarm input
		checkdisarm();

		// if not in disarmed mode
		if(disarmed == false){
			drivetrain();
			shooting_system(127,127);
			claw_system(127,127);
		}

		// if in disarmed mode


		//test();
		// // checks if the middle button is pressed
		// inDiagnostics();
		//
		// // if not in diagnostics mode
		// if(inDiagnostics_state == false){
		// 	drivetrain();
		// }
		// // if in diagnostics mode, run test function
		// else{
		// 	test();
		// }
	}
}
