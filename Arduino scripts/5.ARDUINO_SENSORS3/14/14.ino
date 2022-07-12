int led = 6;
int sound_digital = 7;
int val = 0;
int sound_analog = A0;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sound_digital, INPUT);  
}

void loop()
{
  val = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);
  Serial.print(val_analog);
  Serial.print("\t");
  Serial.println(val);
  
  // when the sensor detects a signal above the threshold value, LED flashes.
  if (val == HIGH)
  {
    digitalWrite (led, HIGH);
    delay(500);
  }
  else
  {
    digitalWrite (led, LOW);
  }
}

  
