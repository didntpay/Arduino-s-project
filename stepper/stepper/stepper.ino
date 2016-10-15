/*
* MotorKnob
*
* A stepper motor follows the turns of a potentiometer
* (or other sensor) on analog input 0.
*
* http://www.arduino.cc/en/Reference/Stepper
* This example code is in the public domain.
*/

#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 64

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;

void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  stepper.setSpeed(15);
}

void loop()
{
  // get the sensor value
  int val = analogRead(0);

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val);

  // remember the previous value of the sensor
  previous = val;
}
