#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>

#define echo_pin A4
#define Trig_pin A0 
#define servo_pin 10

#define MAX_DISTANCE 200
#define MAX_SPEED 200

NewPing mysonar(Trig_pin, echo_pin, MAX_DISTANCE);
Servo myservo;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

boolean goesForward = false;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(servo_pin);
  myservo.write(90);
  delay(50);
  motor1.setSpeed(MAX_SPEED);          
  motor2.setSpeed(MAX_SPEED);
  motor3.setSpeed(MAX_SPEED);
  motor4.setSpeed(MAX_SPEED);
}

void loop() 
{
  int distance = Readping();
  Serial.println(distance);
  int distanceR = 0;
  int distanceL = 0;
  delay(100);
  
  if(distance < 20)
  {
    Stop();
    delay(100);
    Backward();
    delay(500);
    Stop();
    delay(200);
    distanceR = Lookright();
    delay(200);
    distanceL = Lookleft();
    delay(200);
  
    if(distanceR >= distanceL)
    {
      Right();
      Stop();
    }
    else
    {
      Left();
      Stop();
    } 
  }
  else
  {
    Forward();
  }
}

//Functions
int Lookright()
{  
  myservo.write(0);
  delay(500);
  int distance = Readping();
  delay(100);
  myservo.write(90);
  delay(50);
  return distance;
}

int Lookleft()
{
  myservo.write(180);
  delay(500);
  int distance = Readping();
  delay(100);
  myservo.write(90);
  delay(50);
  return distance;
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

void Forward()
{
  if(!goesForward)//Only once if distance > 20.
  //Then, at every loop it goes with max speed, it doesnt go in this if every time.
  {
    goesForward = true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);    

    // slowly bring the speed up to avoid loading down the batteries too quickly
    for (int speed1 = 0; speed1 < MAX_SPEED; speed1 += 2) 
    {
      motor1.setSpeed(speed1);
      motor2.setSpeed(speed1);
      motor3.setSpeed(speed1);
      motor4.setSpeed(speed1);
      delay(5);
    }
  }
}

void Backward()
{
  goesForward = false;
  motor1.run(BACKWARD);      
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);  

  // slowly bring the speed up to avoid loading down the batteries too quickly
  for (int speed1 = 0; speed1 < MAX_SPEED; speed1 += 2) 
  {
    motor1.setSpeed(speed1);
    motor2.setSpeed(speed1);
    motor3.setSpeed(speed1);
    motor4.setSpeed(speed1);
    delay(5);
  }
}

void Right()
{
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(1300);
  delay(1000);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void Left()
{
  motor1.run(BACKWARD); 
  motor2.run(BACKWARD); 
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1300);
  delay(1000);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void Stop()
{
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
