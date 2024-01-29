#ifndef MOVEMENT_H
#define MOVEMENT_H

// movement functions
void forward();
void reverse();
void turn_starboard();
void turn_port();
void fullstop();

// pwm stuff
#define MOTOR_MAX_DUTY_CYCLE 65025
#define MOTOR_ENABLE_FREQ 1500
#define MOTOR_CLK_DIV 125
#define MOTOR_WRAP_VALUE (125000000 / (MOTOR_CLK_DIV * MOTOR_ENABLE_FREQ)) - 1

#endif
