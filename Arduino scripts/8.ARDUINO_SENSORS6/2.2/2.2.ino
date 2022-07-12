#define MQ3pin 8

int sensorValue;  //variable to store sensor value

void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ3 warming up!");
  //delay(20000); // allow the MQ3 to warm up
}

void loop() {
  sensorValue = digitalRead(MQ3pin); // read digital output pin
  Serial.print("Digital Output: ");
  Serial.print(sensorValue);
  
  // Determine the status
  if (sensorValue) {
    Serial.println("  |  Alcohol: -");
  } 
  else {
    Serial.println("  |  Alcohol: Detected!");
  }
  
  delay(2000); // wait 2s for next reading
}
