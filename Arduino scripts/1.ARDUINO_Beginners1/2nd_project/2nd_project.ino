void setup() 
{
  pinMode(6,OUTPUT);
}

void loop() 
{
  //OPEN THE LED.
  for(int i=0; i<=255; i++)
  {
    analogWrite(6,i);
    delay(20);//WAIT 20ms.
  }

  //CLOSE THE LED.
  for(int i=255; i>=0; i--)
  {
    analogWrite(6,i);
    delay(20);//WAIT 20ms.
  }
  
  delay(1000);//WAIT 1SEC.
}
