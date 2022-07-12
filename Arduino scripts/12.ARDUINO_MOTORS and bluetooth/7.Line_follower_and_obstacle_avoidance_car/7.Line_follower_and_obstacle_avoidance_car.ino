#include <AFMotor.h>
#include <NewPing.h>
#define Left_sensor A1
#define Right_sensor A2
#define echo_pin A4
#define Trig_pin A5 

#define MAX_DISTANCE 200
#define MAX_SPEED 200

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

NewPing mysonar(Trig_pin, echo_pin, MAX_DISTANCE);

int threshold = 88;

void setup() 
{
  //Set initial speed of the motor&stop
  motor1.setSpeed(MAX_SPEED);
  motor2.setSpeed(MAX_SPEED);
  motor3.setSpeed(MAX_SPEED);
  motor4.setSpeed(MAX_SPEED);
  pinMode(Right_sensor, INPUT); 
  pinMode(Left_sensor, INPUT); 
}

void loop() 
{
  uint8_t i;
  int distance = Readping();

  if(distance < 15)
  {
    //avoid the obstacle.
    Right();
    Left();
  }
  else
  {
      //follow the line.
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
        motor1.setSpeed(130);
        motor2.setSpeed(130);
        motor3.setSpeed(130);
        motor4.setSpeed(130);
        motor1.run(BACKWARD); 
        motor2.run(BACKWARD); 
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);           
      }
  }
}

int Readping()
{
  int cm = mysonar.ping_cm();
  if (cm==0)
  {
    cm=250;
  }
  return cm;
}

void Right()
{
  motor1.setSpeed(130);
  motor2.setSpeed(130);
  motor3.setSpeed(130);
  motor4.setSpeed(130);
  motor1.run(BACKWARD); 
  motor2.run(BACKWARD); 
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(200); 
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(1300);
  motor1.setSpeed(140);
  motor2.setSpeed(140);
  motor3.setSpeed(140);
  motor4.setSpeed(140);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1000);
}

void Left()
{
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor1.run(BACKWARD); 
  motor2.run(BACKWARD); 
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1100);
  motor1.setSpeed(140);
  motor2.setSpeed(140);
  motor3.setSpeed(140);
  motor4.setSpeed(140);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(500);
}
