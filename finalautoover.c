#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S3,     ir,             sensorI2CCustom)
#pragma config(Motor,  motorA,          pull,          tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftTop,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     leftBot,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     lift,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     rightTop,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     rightBot,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S2_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

#include "hitechnic-irseeker-v2.h"

int _dirAC = 0;
int acS1, acS2, acS3, acS4, acS5 = 0;
tHTIRS2DSPMode _mode = DSP_1200;


void initializeRobot() //sets motor encoders to 0
{
		nMotorEncoder[leftTop] = 0;
		nMotorEncoder[rightTop] = 0;
		servo[servo1] = 90;
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
	//place shit here boys
}