#ifndef PINS_H
#define PINS_H

#include <cstdint>
#include <map>

// motor pins

// left front
#define MOTOR_LEFT_FRONT_ENABLE 10
#define MOTOR_LEFT_FRONT_INPUT_1 11
#define MOTOR_LEFT_FRONT_INPUT_2 12

// left rear
#define MOTOR_LEFT_REAR_ENABLE 13
#define MOTOR_LEFT_REAR_INPUT_1 14
#define MOTOR_LEFT_REAR_INPUT_2 15

// right front
#define MOTOR_RIGHT_FRONT_ENABLE 21
#define MOTOR_RIGHT_FRONT_INPUT_1 20
#define MOTOR_RIGHT_FRONT_INPUT_2 19

// right rear
#define MOTOR_RIGHT_REAR_ENABLE 16
#define MOTOR_RIGHT_REAR_INPUT_1 17
#define MOTOR_RIGHT_REAR_INPUT_2 18

struct MotorPins
{
	uint8_t input1;
	uint8_t input2;
	uint8_t enable;
};

extern std::map<uint8_t, MotorPins> Motors;

#endif // PINS_H
