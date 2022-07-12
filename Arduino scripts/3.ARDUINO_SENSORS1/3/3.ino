#define buzzer 9

void setup() 
{
   //Serial.begin(9600);
   pinMode(buzzer, OUTPUT);
   pinMode(A0, INPUT);
}

void loop() 
{
  int pot_value = analogRead(A0);//WE READ THE POTENTIOMETER VALUE.
  int value=map(pot_value, 0, 1023, 0, 4000);
  //Serial.println(value);
  //tone(buzzer, value);
  //delay(1000);
  tone(buzzer, value, 20);
  delay(500);
}
