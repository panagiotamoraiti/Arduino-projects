void setup() 
{
  pinMode(3, INPUT_PULLUP);
  pinMode(2, OUTPUT);
}

void loop() 
{
  int button_state=digitalRead(3);
  if(button_state==LOW)
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
  delay(100);
}
