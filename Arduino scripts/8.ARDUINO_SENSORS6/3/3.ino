const int ledPin = 13;      
const int knockSensor = A0; 
const int threshold = 150;//threshold value to decide when the detected sound is a knock or not
int sensorReading = 0;          

void setup() 
{
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);      
}

void loop() 
{
  sensorReading = analogRead(knockSensor);
  Serial.println(sensorReading);

  if (sensorReading >= threshold) 
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("Knock!");
    delay(1000);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("");
  }
  delay(1000);
}
