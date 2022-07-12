void setup() 
{
  pinMode(13,OUTPUT);
}

void loop() 
{
  digitalWrite(13,HIGH);//OPEN THE LED.
  delay(1000);//WAIT 1SEC.
  digitalWrite(13,LOW);//CLOSE THE LED.
  delay(1000);//WAIT 1SEC.
}
