void setup()
{
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
}

void loop()
{
  int tiltstate=digitalRead(7);
  if(tiltstate==HIGH)
  {
    digitalWrite(6,HIGH);
  }
  else
  {
    digitalWrite(6,LOW);
  }
}
