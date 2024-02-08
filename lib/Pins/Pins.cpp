#include <Pins.h>
#include <cstdint>
#include <map>

// define the motor pins so we can look it up in a map, keyed by the enable pin
std::map<uint8_t, MotorPins> Motors = {
		{MOTOR_LEFT_FRONT_ENABLE, {MOTOR_LEFT_FRONT_INPUT_1, MOTOR_LEFT_FRONT_INPUT_2, MOTOR_LEFT_FRONT_ENABLE}},
		{MOTOR_LEFT_REAR_ENABLE, {MOTOR_LEFT_REAR_INPUT_1, MOTOR_LEFT_REAR_INPUT_2, MOTOR_LEFT_REAR_ENABLE}},
		{MOTOR_RIGHT_FRONT_ENABLE, {MOTOR_RIGHT_FRONT_INPUT_1, MOTOR_RIGHT_FRONT_INPUT_2, MOTOR_RIGHT_FRONT_ENABLE}},
		{MOTOR_RIGHT_REAR_ENABLE, {MOTOR_RIGHT_REAR_INPUT_1, MOTOR_RIGHT_REAR_INPUT_2, MOTOR_RIGHT_REAR_ENABLE}}};