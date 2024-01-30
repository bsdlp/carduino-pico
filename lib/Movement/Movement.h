#ifndef MOVEMENT_H
#define MOVEMENT_H

// movement functions
void forward();
void reverse();
void turn_starboard();
void turn_port();
void fullstop();

// pwm stuff
// for more on what the values mean: https://forums.raspberrypi.com/viewtopic.php?t=309632
#define MOTOR_ENABLE_FREQ 1500
#define MOTOR_CLK_DIV 1
#define MOTOR_WRAP_VALUE (125000000 / (MOTOR_CLK_DIV * MOTOR_ENABLE_FREQ)) - 1

#endif
