const int ledPin = 13;
const int buzzer = 9;

void setup()
{
   pinMode(ledPin, OUTPUT);
   pinMode(buzzer, OUTPUT);
}

void loop()
{
   int sensorValue = analogRead(A0);
   if(sensorValue<=512) { 
    digitalWrite(ledPin,HIGH); } 
   else { 
    digitalWrite(ledPin,LOW); } 
    
   int freq = map(sensorValue, 0, 1023, 0, 4000);
   tone(buzzer, freq);
   delay(1000);
}
