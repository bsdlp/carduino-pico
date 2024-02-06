#ifndef MOVEMENT_H
#define MOVEMENT_H

// movement functions
void set_speed(unsigned int motor_pin, int speed);

// pwm stuff
// for more on what the values mean: https://forums.raspberrypi.com/viewtopic.php?t=309632
// https://forums.raspberrypi.com/viewtopic.php?f=145&t=307912#p1844432
#define MOTOR_ENABLE_FREQ 1500
#define MOTOR_CLK_DIV 1
#define MOTOR_WRAP_VALUE ((uint16_t)(125000000 / (MOTOR_CLK_DIV * MOTOR_ENABLE_FREQ)) - 1)

#endif
