int LED = 4; 
int FlamePin = A0;  // This is our input pin
int Flame;
int buzzer = 3;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(FlamePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Flame = analogRead(FlamePin);
  if (Flame < 1023)
  {
    Serial.println("Fire!!!");
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    Serial.println("No fire");
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
  }
  //Serial.println(Flame);
  //Serial.println();
  delay(1000);
}
