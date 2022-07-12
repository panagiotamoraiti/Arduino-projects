#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() 
{
  Serial.begin(9600);
  //Set initial speed of the motor & stop
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop() 
{
  uint8_t i;
  
  if(Serial.available())
  {
    char c = Serial.read();
    Serial.println(c);
    if(c == '1')
    {
      motor1.run(FORWARD); 
      motor2.run(FORWARD); 
      motor3.run(FORWARD);
      motor4.run(FORWARD); 
    }
    else if(c == '2')
    {
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD); 
      motor3.run(BACKWARD);
      motor4.run(BACKWARD); 
    }
    else if(c == '3')
    {
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD); 
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    }
    else if(c == '4')
    {
      motor1.run(FORWARD); 
      motor2.run(FORWARD); 
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    }
    else if(c == '5')
    {
      motor1.run(RELEASE); 
      motor2.run(RELEASE); 
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
    delay(50);
  }
}
