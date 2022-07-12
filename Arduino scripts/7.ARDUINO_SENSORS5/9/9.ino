#include <NewPing.h> 
#define TRIGGER_PIN 8 
#define ECHO_PIN 9 
#define MAX_DISTANCE 200 
#define pump 7
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//We declare the object sonar. 
const int height = 9;// Put the height in cm of your tank.

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(pump, OUTPUT);
} 

void loop() 
{ 
  int x=sonar.ping_cm();//x is the distance in cm. 
  int y = height-x;
  //Serial.println(x);
  Serial.print("Water height: ");
  Serial.print(y);
  Serial.println(" cm");
  if(y<=height/2)
  {
     digitalWrite(pump, HIGH);
     Serial.println("Pump is working");
  }
  else
  {
    digitalWrite(pump, LOW);
    Serial.println("The height of the water is more than half the height of the tank.");
  }
  Serial.println("");
  delay(1000); 
}
