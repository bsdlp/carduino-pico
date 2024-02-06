#include <Arduino.h>
#include <Pins.h>
#include <Movement.h>
#include <pico/stdlib.h>
#include <hardware/pwm.h>
#include <JoystickBLE.h>

// put function declarations here:
void setPinModes();
void setupPwmPin(uint pin);

void setupPwmPin(uint pin)
{
  gpio_set_function(pin, GPIO_FUNC_PWM);

  int pwmSlice = pwm_gpio_to_slice_num(pin);

  // disable pwm slice before configuring
  pwm_set_enabled(pwmSlice, false);

  // Set the PWM clock divider and mode
  pwm_set_clkdiv_mode(pwmSlice, PWM_DIV_FREE_RUNNING);
  pwm_set_clkdiv(pwmSlice, MOTOR_CLK_DIV);

  // Calculate the wrap value based on the desired frequency
  pwm_set_wrap(pwmSlice, MOTOR_WRAP_VALUE);

  // Re-enable the PWM slice
  pwm_set_enabled(pwmSlice, true);
}

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
  setupPwmPin(MOTOR_LEFT_FRONT_ENABLE);
  setupPwmPin(MOTOR_RIGHT_FRONT_ENABLE);
  setupPwmPin(MOTOR_LEFT_REAR_ENABLE);
  setupPwmPin(MOTOR_RIGHT_REAR_ENABLE);

  JoystickBLE.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  set_speed(MOTOR_LEFT_FRONT_ENABLE, 100);
  delay(1000);
  set_speed(MOTOR_LEFT_FRONT_ENABLE, 0);
  delay(200);
}
