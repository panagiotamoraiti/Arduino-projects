#include <NewPing.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//We declare the object sonar.

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
 int x=sonar.ping_cm();//x is the distance in cm.
 Serial.print("The distance is: ");
 Serial.print(x);
 Serial.println(" cm.");
 delay(1000);
}
