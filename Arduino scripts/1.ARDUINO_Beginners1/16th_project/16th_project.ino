#include <NewPing.h>

#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200
#define RED 9
#define GREEN 10
#define BLUE 11


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() 
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() 
{
  int distance=sonar.ping_cm();
  if(distance>=0 && distance<=10)//RED
  {
    Serial.print("Dont go any further, danger at ");
    Serial.print(distance);
    Serial.println(" cm.");
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
  else if(distance>10 && distance<=30)//BLUE
  {
    Serial.print(distance);
    Serial.println(" cm remaining,stop here or proceed carefully.");
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  }
  else if(distance>30 && distance<=50)//GREEN
  {
    Serial.print(" Found obstacle at ");
    Serial.print(distance);
    Serial.println(" cm.");
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE,LOW);
  }
  else//distance<0 || distance>50.//ALL LEDS CLOSED.
  {
    //Do nothing.
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE,LOW);
  }
  
  delay(500);
}
