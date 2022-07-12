//Includes the Arduino Stepper Library
#include <Stepper.h>
// Define Constants
 
// Number of steps per internal motor revolution 
const float stepsPerRevolution = 32; 
 
//  Amount of Gear Reduction
const float gear_red = 64;
 
// Number of steps per geared output rotation
const float stepsOutPerRevolution = stepsPerRevolution * gear_red;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Nothing to do (Stepper Library sets pins as outputs)
}

void loop() {
  // Rotate CW slowly
  myStepper.setSpeed(700);
  myStepper.step(stepsOutPerRevolution);
  delay(1000);
  
  // Rotate CCW quickly
  myStepper.setSpeed(100);
  myStepper.step(-stepsOutPerRevolution);
  delay(1000);
}
