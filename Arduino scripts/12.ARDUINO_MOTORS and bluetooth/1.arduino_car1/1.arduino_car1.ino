#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() 
{
  //Set initial speed of the motor & stop
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop() 
{
  uint8_t i;
  
  // Turn on motors
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD);
  motor4.run(FORWARD); 
  delay(3000);

  //Turn left
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD); 
  delay(1250);
  
  // Turn on motors
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD); 
  delay(3000);

  //Turn right
  motor1.run(BACKWARD); 
  motor2.run(BACKWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD); 
  delay(1250);
  
  // Turn on motors
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD); 
  delay(3000);

  // Turn off motors
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  motor3.run(RELEASE); 
  motor4.run(RELEASE); 
  delay(3000);
}
