
/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 250;  // change this to fit the number of steps per revolution
// for your motor
const int speedMotor = 100, timeOn = 1000, timeOff = 3000;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  // number of steps the motor has taken
int i =0;
bool on = false;

void myMotorSetup(){
  myStepper.setSpeed(speedMotor);
}

void stepMotor() {
  i++;
  //Serial.print(i);
  //Serial.print("\n");
  
  if(i < timeOn && !on){
      on = true;
      //SERIAL DEBUG
      Serial.print("Motor On at :");
      Serial.print(i);
      Serial.print("\n");
    }else if(i > timeOff){
      i=0;
    }else if(on && i>timeOn && i<timeOff){
      on = false;
      //SERIAL DEBUG
      Serial.print("Motor Off at :");
      Serial.print(i);
      Serial.println("\n");
    }

    if(on)
      myStepper.step(stepsPerRevolution/100);
}
