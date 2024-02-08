#include <Arduino.h>
#include <Pins.h>
#include <Movement.h>
#include <JoystickBLE.h>

// put function declarations here:
void setPinModes();

void setPinModes()
{
  // left front motor
  pinMode(MOTOR_LEFT_FRONT_INPUT_1, OUTPUT);
  pinMode(MOTOR_LEFT_FRONT_INPUT_2, OUTPUT);

  // right front motor
  pinMode(MOTOR_RIGHT_FRONT_INPUT_1, OUTPUT);
  pinMode(MOTOR_RIGHT_FRONT_INPUT_2, OUTPUT);

  // left rear motor
  pinMode(MOTOR_LEFT_REAR_INPUT_1, OUTPUT);
  pinMode(MOTOR_LEFT_REAR_INPUT_2, OUTPUT);

  // right rear motor
  pinMode(MOTOR_RIGHT_REAR_INPUT_1, OUTPUT);
  pinMode(MOTOR_RIGHT_REAR_INPUT_2, OUTPUT);
}

void setup()
{
  setPinModes();
  JoystickBLE.begin();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  set_speed(MOTOR_LEFT_FRONT_ENABLE, 255);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  set_speed(MOTOR_LEFT_FRONT_ENABLE, 0);
  delay(200);
}
