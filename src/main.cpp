#include <Arduino.h>
#include <Pins.h>
#include <hardware/pwm.h>
#include <JoystickBLE.h>

// put function declarations here:
void setPinModes();
void setupPwmPin(uint pin);

void setupPwmPin(uint pin)
{
  pinMode(pin, OUTPUT);

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

  // Set the duty cycle (e.g., 50%)
  pwm_set_gpio_level(pin, MOTOR_WRAP_VALUE / 2);
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
  // pwm frequency at 1500hz
  analogWriteFreq(MOTOR_ENABLE_FREQ);
  analogWriteRange(MOTOR_MAX_DUTY_CYCLE);

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
}
