int laserPin = 7;

void setup() 
{                
  pinMode(laserPin, OUTPUT);  
}

void loop() 
{
  digitalWrite(laserPin, HIGH); //Open the laser
  delay(1000); 
  digitalWrite(laserPin, LOW); //Close the laser 
  delay(1000); 
}
