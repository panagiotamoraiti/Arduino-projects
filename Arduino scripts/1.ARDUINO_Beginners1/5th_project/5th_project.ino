void setup() 
{
  pinMode(11,OUTPUT);
  pinMode(A2,INPUT);

}

void loop() 
{
  int x=analogRead(A2);//READ THE POTENTIOMETER VALUE.
  x=x/4;//CONVERT VALUE FROM 1024 TO 255.
  analogWrite(11,x);//OPEN THE LED IN THE ANALOG VALUE X THAT WE TOOK FROM THE POTENTIOMETER.
}
