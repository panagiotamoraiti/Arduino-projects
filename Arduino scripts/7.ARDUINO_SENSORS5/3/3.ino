int laserPin = 7;
int photoresistor = A0;
int buzzer = 2;

void setup() 
{                
  pinMode(laserPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(laserPin, HIGH); //Open the laser
  int photoresistor_value = analogRead(photoresistor);
  Serial.println();
  
  if(photoresistor_value >= 600)
  {
    Serial.println("NO Motion");
    digitalWrite(buzzer, LOW);
  }
  else
  {
    Serial.println("Motion detected!");
    digitalWrite(buzzer, HIGH);
  }
  delay(300);
}
