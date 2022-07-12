float sensorValue;  

void setup()
{
  Serial.begin(9600); 
  delay(20000);//allow the MQ-6 to warm up
}

void loop()
{
  sensorValue = analogRead(A0);//read analog input
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  if(sensorValue > 200)
  {
    Serial.println("Smoke detected!");
  }
  Serial.println("");
  delay(1000); 
}
