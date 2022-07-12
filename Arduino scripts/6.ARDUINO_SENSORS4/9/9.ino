int OptoPin=7;

void setup()
{
  pinMode(OptoPin, OUTPUT); 
}

void loop()
{
  digitalWrite(OptoPin, LOW);  
  delay(500); 
  digitalWrite(OptoPin, HIGH);
  delay(500); 
}
