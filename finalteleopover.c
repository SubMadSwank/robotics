#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     L1,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     L2,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     R1,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_2,     R2,      tmotorTetrix, openLoop, reversed)

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

/////////////////////////
//   Easy Button Names
/////////////////////////

int x = joy1Btn(1);
int a = joy1Btn(2);
int b = joy1Btn(3);
int y = joy1Btn(4);
int lClick = joy1Btn(5);
int rClick = joy1Btn(6);
int lTrig = joy1Btn(7);
int rTrig = joy1Btn(8);
int select = joy1Btn(9);
int start = joy1Btn(10);
int lThumb = joy1Btn(11);
int rThumb = joy1Btn(12);

////////////////////////
//  dPad Buttons
////////////////////////

int dOad = joystick.joy1_TopHat;

int up = 0;
int right = 2;
int down = 4;
int left = 6;

void initializeRobot()
{
		//nMotorEncoder[L1] = 0;
		//nMotorEncoder[lift] = 0;
		return;
}

void movement(int speed)
{
		motor[L1] = speed;
		motor[L2] = speed;
		motor[R1] = speed;
		motor[R2] = speed;
		//moves robot all in the same direction
}

void rotateLeft(int speed)
{
		motor[L1] = speed;
		motor[L2] = speed;
		motor[R1] = -speed;
		motor[R2] = -speed;
		//rotates left ccw
}

void rotateRight(int speed)
{
		motor[L1] = -speed;
		motor[L2] = -speed;
		motor[R1] = speed;
		motor[R2] = speed;
		//rotates right cw
}

task main(){

	initializeRobot();

 	while (true)
		{
		getJoystickSettings(joystick);

		if (dPad == up){
		movement(-95);
 		}//moves forward

		else if (dPad == right){
		rotateRight(95);
  		}//moves cw

  		else if (dPad == down){
		movement(95);
  		}//moves backward

  		else if (dPad == left){
  		rotateLeft(95);
  		}//moves ccw

  		else{
  			if (abs(joystick.joy1_y1)  > 7 || abs(joystick.joy1_y2) > 7){
  				motor[L1] = joystick.joy1_y1 * .78125;
				motor[L2] = joystick.joy1_y1 * .78125;
				motor[R1] = joystick.joy1_y2 * .78125;
				motor[R2] = joystick.joy1_y2 * .78125;
			}

			else if (rClick == 1){
				motor[lift] = 100;
			}

			else if (rTrig == 1){
				motor[lift] = -100;
			}

			else if (a == 1){
				motor[sweep] = 100;
			}

			else if (b == 1){
				motor[sweep] = -100;
			}

  			else{
  				motor[L1] = 0;
				motor[L2] = 0;
				motor[R1] = 0;
  				motor[lift]= 0;
  				motor[sweep] = 0;
  			}
 		}
	}
}
