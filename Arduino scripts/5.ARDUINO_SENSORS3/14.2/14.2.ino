int led = 6;
int sound_digital = 7;
int val = 0;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(sound_digital, INPUT);  
}

void loop()
{
  val = digitalRead(sound_digital);
  // when the sensor detects a signal above the threshold value, LED flashes.
  if (val == HIGH)
  {
    digitalWrite (led, HIGH);
    delay(10);
  }
  else
  {
    digitalWrite (led, LOW);
  }
}
