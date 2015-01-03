#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftTop,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     leftBot,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     rightTop,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     rightBot,      tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*// 

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot() //sets motor encoders to 0 
{
		nMotorEncoder[leftTop] = 0;
		nMotorEncoder[rightTop] = 0;
		return;
}

void robotMotion(int speed)
{
		motor[leftTop] = speed;
		motor[leftBot] = speed;
		motor[rightTop] = speed;
		motor[rightBot] = speed;
		//moves robot all in the same direction
}

void rotateLeft(int speed)
{
		motor[leftTop] = speed;
		motor[leftBot] = speed;
		motor[rightTop] = -speed;
		motor[rightBot] = -speed;
		//rotates left ccw
}

void rotateRight(int speed)
{
		motor[leftTop] = -speed;
		motor[leftBot] = -speed;
		motor[rightTop] = speed;
		motor[rightBot] = speed;
		//rotates right cw
}

task main(){

	initializeRobot();

 	while (true)
		{
		getJoystickSettings(joystick);

		if (joystick.joy1_TopHat == 0){
		robotMotion(-95);
 		}//moves forward

		else if (joystick.joy1_TopHat == 2){
		rotateRight(95);
  		}//moves cw

  		else if (joystick.joy1_TopHat == 4){
		robotMotion(95);
  		}//moves backward

  		else if (joystick.joy1_TopHat == 6){
  		rotateLeft(95);
  		}//moves ccw

  		else{
  			if (abs(joystick.joy1_y1)  > 7 || abs(joystick.joy1_y2) > 7){
  				motor[leftTop] = -joystick.joy1_y1 * .78125;
				motor[leftBot] = -joystick.joy1_y1 * .78125;
				motor[rightTop] = -joystick.joy1_y2 * .78125;
				motor[rightBot] = -joystick.joy1_y2 * .78125;
			}

			else{
				motor[leftTop] = 0;
				motor[leftBot] = 0;
				motor[rightTop] = 0;
				motor[rightBot] = 0;
			}

			if (joy1Btn(6) == 1){
				motor[lift] = 90;
			}

			else if (joy1Btn(8) == 1){
				motor[lift] = -90;
			}

			else if (joy1Btn(2) == 1){
				motor[sweep] = 100;
			}

			else if (joy1Btn(3) == 1){
				motor[sweep] = -100;
			}

  			else{
  				motor[lift]= 0;
  				motor[sweep] = 0;
  			}
 		}
	}
}
