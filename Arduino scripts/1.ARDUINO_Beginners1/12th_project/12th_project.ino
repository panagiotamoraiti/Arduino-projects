#include <Servo.h>
Servo myservo;//we declare our servo.

void setup() 
{
  Serial.begin(9600);//serial communication.
  myservo.attach(9);//we attach servo to a pin.
}

void loop() 
{
  myservo.write(0);//we write degrees to the servo(we tell the servo where to go).
  Serial.println("We are at 0 degrees!");
  delay(1500);
  myservo.write(180);
  Serial.println("We are at 180 degrees!");
  delay(1500);
}
