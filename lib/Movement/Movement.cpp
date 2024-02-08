#include <Movement.h>
#include <Pins.h>
#include <map>
#include <string>
#include <Arduino.h>

void set_speed(uint8_t motor, int64_t speed)
{
	// TODO: look up the correct pins for motors based on motor number
	if (speed > 0)
	{
		// forward
		/*
			digitalWrite(in1, LOW);
			digitalWrite(in2, HIGH);
		*/
		digitalWrite(Motors[motor].input1, HIGH);
		digitalWrite(Motors[motor].input2, LOW);
	}
	else
	{
		// backward
		/*
			digitalWrite(in1, HIGH);
			digitalWrite(in2, LOW);
		*/
		digitalWrite(Motors[motor].input1, LOW);
		digitalWrite(Motors[motor].input2, HIGH);
	}

	// set the speed of the motor
	// 0-255
	analogWrite(Motors[motor].enable, abs(speed));
}
