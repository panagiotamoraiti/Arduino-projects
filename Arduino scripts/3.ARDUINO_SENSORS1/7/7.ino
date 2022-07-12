//Το const int χρησιμοποιείται σαν το #define.
const int redLEDPin = 9;
const int greenLEDPin = 10;
const int blueLEDPin = 11;
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

void setup()
{
   Serial.begin(9600);
   pinMode(greenLEDPin,OUTPUT);
   pinMode(redLEDPin,OUTPUT);
   pinMode(blueLEDPin,OUTPUT);
}
void loop() 
{
   int redSensorValue = analogRead(redSensorPin);
   int greenSensorValue = analogRead(greenSensorPin);
   int blueSensorValue = analogRead(blueSensorPin);

   int redValue = redSensorValue/4;
   delay(5);
   int greenValue = greenSensorValue/4;
   delay(5);
   int blueValue = blueSensorValue/4;
   
   Serial.print("Mapped Sensor Values \t Red: ");
   Serial.print(redValue);
   Serial.print("\t Green: ");
   Serial.print(greenValue);
   Serial.print("\t Blue: ");
   Serial.println(blueValue);
   
   analogWrite(redLEDPin, redValue);
   analogWrite(greenLEDPin, greenValue);
   analogWrite(blueLEDPin, blueValue);
   delay(500);
}
  
