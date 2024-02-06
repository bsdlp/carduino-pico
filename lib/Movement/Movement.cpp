#include <Movement.h>
#include <Pins.h>
#include <pico/stdlib.h>
#include <cstdlib>
#include <hardware/pwm.h>

void set_speed(unsigned int motor, int speed)
{
	// TODO: look up the correct pins for motors based on motor number
	if (speed > 0)
	{
		// forward
		/*
			digitalWrite(in1, LOW);
			digitalWrite(in2, HIGH);
		*/
		gpio_put(motor, true);
	}
	else
	{
		// backward
		/*
			digitalWrite(in1, HIGH);
			digitalWrite(in2, LOW);
		*/
		gpio_put(motor, false);
	}

	// set the speed of the motor
	// 0-255
	pwm_set_gpio_level(motor, abs(speed));
}
