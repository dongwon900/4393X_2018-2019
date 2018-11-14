#include "main.h"
#include "drivetrain.h"
#include "claw_system.h"
#include "shooting_system.h"
#include "plant_system.h"
#include "test.h"

void autonomous_test(){
  motorSet(6, 127);
  delay(1000);

	motorSet(6,0);
}

// the operatorControl
void operatorControl() {
	while (1) {
		// checks for disarm input
		checkdisarm();

		// if not in disarmed mode
		if(disarmed == false){
			if (joystickGetDigital(1, 7, JOY_LEFT)) {
				if(joystickGetDigital(1, 8, JOY_RIGHT)) {
					autonomous_test();
				}
			}

			if (joystickGetDigital(1, 7, JOY_LEFT)) {
				if(joystickGetDigital(1, 8, JOY_LEFT)) {
					adjustDistance(12); //should run the funtion and put the robot 12 centimeters away from the object in front of the ultrasonic
				}
			}

			drivetrain();
			shooting_system(127,127);
			claw_system(127,127);
			lifter();
			test();

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
