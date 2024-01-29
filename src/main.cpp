#include <Arduino.h>
#include <Pins.h>

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);

  // left front motor
  pinMode(MOTOR_LEFT_FRONT_ENABLE, OUTPUT);
  pinMode(MOTOR_LEFT_FRONT_INPUT_1, OUTPUT);
  pinMode(MOTOR_LEFT_FRONT_INPUT_2, OUTPUT);

  // right front motor
  pinMode(MOTOR_RIGHT_FRONT_ENABLE, OUTPUT);
  pinMode(MOTOR_RIGHT_FRONT_INPUT_1, OUTPUT);
  pinMode(MOTOR_RIGHT_FRONT_INPUT_2, OUTPUT);

  // left rear motor
  pinMode(MOTOR_LEFT_REAR_ENABLE, OUTPUT);
  pinMode(MOTOR_LEFT_REAR_INPUT_1, OUTPUT);
  pinMode(MOTOR_LEFT_REAR_INPUT_2, OUTPUT);

  // right rear motor
  pinMode(MOTOR_RIGHT_REAR_ENABLE, OUTPUT);
  pinMode(MOTOR_RIGHT_REAR_INPUT_1, OUTPUT);
  pinMode(MOTOR_RIGHT_REAR_INPUT_2, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}