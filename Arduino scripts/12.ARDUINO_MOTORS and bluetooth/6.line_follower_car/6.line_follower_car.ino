#include <AFMotor.h>
#define Left_sensor A1
#define Right_sensor A2

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int threshold = 100;

void setup() 
{
  pinMode(Right_sensor, INPUT); 
  pinMode(Left_sensor, INPUT); 
}

void loop() 
{
  uint8_t i;
  int LEFT_SENSOR = analogRead(Left_sensor);
  int RIGHT_SENSOR = analogRead(Right_sensor);

  if(RIGHT_SENSOR<threshold && LEFT_SENSOR<threshold){
    //FORWARD
    motor1.setSpeed(140);
    motor2.setSpeed(140);
    motor3.setSpeed(140);
    motor4.setSpeed(140);
    motor1.run(FORWARD); 
    motor2.run(FORWARD);  
    motor3.run(FORWARD);
    motor4.run(FORWARD); 
  }
   else if(RIGHT_SENSOR>threshold && LEFT_SENSOR<threshold){ 
    //LEFT
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);
    motor1.run(FORWARD); 
    motor2.run(FORWARD); 
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);          
  }
  else if(RIGHT_SENSOR<threshold && LEFT_SENSOR>threshold){ 
    //RIGHT
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor3.setSpeed(200);
    motor4.setSpeed(200);
    motor1.run(BACKWARD); 
    motor2.run(BACKWARD); 
    motor3.run(FORWARD);
    motor4.run(FORWARD);             
  } 
  else if(RIGHT_SENSOR>threshold && LEFT_SENSOR>threshold){ 
    //Back
    motor1.setSpeed(140);
    motor2.setSpeed(140);
    motor3.setSpeed(140);
    motor4.setSpeed(140);
    motor1.run(BACKWARD); 
    motor2.run(BACKWARD); 
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);           
  }
}
