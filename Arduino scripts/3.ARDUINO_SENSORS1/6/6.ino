void setup()
{
  pinMode(3,OUTPUT);//RED.
  pinMode(5,OUTPUT);//BLUE.
  pinMode(7,OUTPUT);//GREEN.
}

void loop()
{
  int photoresistor_value1=analogRead(A0);//RED.
  int photoresistor_value2=analogRead(A2);//BLUE.
  int photoresistor_value3=analogRead(A4);//GREEN.
  
  if(photoresistor_value1<=512)// 1024/2=512.
  {
    digitalWrite(3,HIGH);
  }
  else
  {
    digitalWrite(3,LOW);
  }
  if(photoresistor_value2<=512)// 1024/2=512.
  {
    digitalWrite(5,HIGH);
  }
  else
  {
    digitalWrite(5,LOW);
  }
  if(photoresistor_value3<=512)// 1024/2=512.
  {
    digitalWrite(7,HIGH);
  }
  else
  {
    digitalWrite(7,LOW);
  }
}
