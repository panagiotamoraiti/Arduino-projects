#include <Servo.h> 
Servo myservo;//we declare our servo. 

void setup() 
{ 
  myservo.attach(6);//we attach servo to a pin. 
  //Serial.begin(9600);
  //pinMode(A0,INPUT); 
} 
void loop() 
{ 
  int pot_val=analogRead(A0);//READ THE POTENTIOMETER VALUE.
  //Serial.println(pot_val);    
  int angle = map(pot_val, 0, 1023, 0, 180);//0-1023 to 0-179.
  myservo.write(angle);
  //Serial.println(angle);
  delay(1000);
}
