void setup() 
{
  Serial.begin(9600);//we begin serial communication.
  pinMode(A0,INPUT);
}

void loop() 
{
  int x=analogRead(A0);
  Serial.print("The analog value is: ");//we print a message.
  Serial.println(x);//we print the potentiometer value.
  delay(1000);
}
