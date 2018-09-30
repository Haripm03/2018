#pragma config(Sensor, S1,     frontIR,        sensorEV3_GenericI2C)
#pragma config(Sensor, S2,     backIR,         sensorEV3_GenericI2C)
#pragma config(Sensor, S4,     compass,        sensorEV3_GenericI2C)
#pragma config(Motor,  motorA,          frontLeft,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          backLeft,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          backRight,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          frontRight,    tmotorEV3_Large, PIDControl, encoder)

int target;
int current;

#define COMPMULTI 0.7

task main ()
{
	clearDebugStream();
	setLEDColor(ledRed); //Robot's light colour set to red

	target = 2.0 * SensorValue[compass]; // Heading of goal is equal to compass value * 2 (0-360)


	waitForButtonPress();// Waiting for any button to be pressed
	setLEDColor(ledGreen); // Sets button colour to green

	while (true)
	{

		current = 2.0 * SensorValue(compass); // Current Heading of robot is equal to compass value * 2 (0-360)

		float rotation = target - current;
		{

			/* This section sets the direction the robot needs to face in a range of -180 to 180.*/
			if (rotation > 180)
			{
				rotation -= 360;
			}
			else if (rotation <= -180)
			{
				rotation += 360;
			}
			rotation *= COMPMULTI;

			motor[frontLeft] = rotation;
			motor[frontRight] = rotation;
			motor[backLeft] = rotation;
			motor[backRight] = rotation;
			writeDebugStreamLine("Current: %d. Target: %d. Rotation: %d", current, target, rotation);
		}
	}
}
