#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define MAX_DISTANCE 180
#define SERVO_PIN 10

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//We declare the object sonar.
Servo myservo;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
}

void loop() 
{
 int angle=sonar.ping_cm();//angle is the distance in cm.
 Serial.print("The distance is: ");
 Serial.print(angle);
 Serial.println(" cm.");
 Serial.print("The angle is: ");
 Serial.print(angle);
 Serial.println(" cm.");
 myservo.write(angle);
 delay(250);  
}
