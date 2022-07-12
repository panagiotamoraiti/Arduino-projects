void setup()
{
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
}

void loop()
{
  int tiltstate=digitalRead(7);
  digitalWrite(6, tiltstate);
  
}
