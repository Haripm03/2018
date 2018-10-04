#pragma config(Sensor, S1,     frontIR,        sensorEV3_GenericI2C)
#pragma config(Sensor, S2,     backIR,         sensorEV3_GenericI2C)
#pragma config(Sensor, S4,     compass,        sensorEV3_GenericI2C)
#pragma config(Motor,  motorA,          frontRight,    tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          frontLeft,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          backLeft,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          backRight,     tmotorEV3_Large, PIDControl, encoder)


#include "hitechnic-compass.h"

#define SPEED 10

tHTMC HTcompass;

task showPulse()
{
	while (true)
	{
		displayCenteredBigTextLine(6, " ");
		sleep(400);
		displayCenteredBigTextLine(6, "*");
		sleep(400);
	}
}

// Start the calibration and complain loudly if something goes wrong
void startCalibration() {
	if (!sensorCalibrate(&HTcompass)) {
		eraseDisplay();
		displayTextLine(1, "ERROR: Couldn't");
		displayTextLine(2, "calibrate sensor.");
		displayTextLine(4, "Check connection");
		displayTextLine(5, "and try again.");
		playSound(soundException);
		while(bSoundActive) sleep(1);
		sleep(5000);
		stopAllTasks();
	}
}

// Stop the calibration and complain loudly if somethign goes wrong
void stopCalibration() {
	if (!sensorStopCalibrate(&HTcompass)) {
		eraseDisplay();
		displayTextLine(1, "ERROR: Calibration");
		displayTextLine(2, "has failed.");
		displayTextLine(4, "Check connection");
		displayTextLine(5, "and try again.");
		playSound(soundException);
		while(bSoundActive) sleep(1);
		sleep(5000);
		stopAllTasks();
		} else {
		displayTextLine(1, "SUCCESS: ");
		displayTextLine(2, "Calibr. done.");
		playSound(soundUpwardTones);
		while(bSoundActive) sleep(1);
		sleep(5000);
	}
}
task main ()
{
	setLEDColor(ledRed); //Robot's light colour set to red
	waitForButtonPress();// Waiting for any button to be pressed
	setLEDColor(ledGreen); // Sets the robot's colour back to green

	displayCenteredTextLine(0, "HiTechnic");
	displayCenteredBigTextLine(1, "HTcompass");
	displayCenteredTextLine(3, "Test 2");

	// Initialise and configure struct and port
	initSensor(&HTcompass, S4);


	startCalibration();
	motor[frontLeft] = SPEED;
	motor[frontRight] = SPEED;
	motor[backRight] = SPEED;
	motor[backLeft] = SPEED;
	displayCenteredTextLine(5, "Calibrating...");
	startTask(showPulse);
	wait1Msec(20000);
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	stopCalibration();
	displayCenteredTextLine(5, "Calibration done");
	sleep(5000);
}
