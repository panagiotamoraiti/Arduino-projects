#define led 13

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() 
{
  if(Serial.available())
  {
    char c = Serial.read();
    if(c == 'a')
    {
      digitalWrite(led, HIGH);
    }
    else if(c == 'b')
    {
      digitalWrite(led, LOW);
    }
    delay(50);
  }
}
