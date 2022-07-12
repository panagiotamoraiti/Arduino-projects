void setup()
{
  pinMode(6,OUTPUT);//led
  pinMode(5,INPUT_PULLUP);
  pinMode(4,OUTPUT);//buzzer
  Serial.begin(9600);
  delay(30000);
}

void loop()
{
  bool motion=digitalRead(5);
  if(motion)
  {
    digitalWrite(6,HIGH);
    tone(4, 1000); //1KHz sound. 
    Serial.println("HIGH");
  }
  else
  {
    digitalWrite(6,LOW);
    noTone(4); // Stop the sound. 
    Serial.println("LOW");
  }
}
