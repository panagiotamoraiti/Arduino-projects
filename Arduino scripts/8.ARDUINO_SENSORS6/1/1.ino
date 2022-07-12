int touchPin = 2;//pin for the touch sensor
int ledPin = 13;//pin for the LED

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); //set the Led Pin to output
  pinMode(touchPin, INPUT);//set the Touch Pin to input
}

void loop() 
{
  int touchValue = digitalRead(touchPin);//read the Touch Pin
  if (touchValue == HIGH) 
  { 
    //check if the sensor is touched
    digitalWrite(ledPin, HIGH);
    Serial.println("Touched!");
  }
  else 
  {
    digitalWrite(ledPin, LOW);
    Serial.println("Not touched.");
  }
  delay(100);
}
