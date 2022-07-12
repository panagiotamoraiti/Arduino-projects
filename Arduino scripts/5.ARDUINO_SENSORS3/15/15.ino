int red=2;
int green=3;
int blue=4;
int buzzer=5;

void setup () 
{
  pinMode (red,OUTPUT);
  pinMode (green,OUTPUT);
  pinMode (blue,OUTPUT);
  pinMode (buzzer,OUTPUT);
  Serial.begin (9600);
}
 
void loop() 
{
  // read the input on analog pin 0:
  int value = analogRead(A0);
  if (value <= 10) 
  {
    Serial.print("Water Level:Empty->");
    Serial.println(value);
    digitalWrite (red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    noTone(buzzer);
  }
  else if((value > 10) && (value <= 660))
  {
    Serial.print("Water Level:LOW->");
    Serial.println(value);
    digitalWrite (blue,HIGH);
    digitalWrite (red,LOW);
    digitalWrite (green,LOW);
    noTone(buzzer);
  }
  else if ((value > 660) && (value <= 680)) 
  {
    Serial.print("Water Level:MEDIUM->");
    Serial.println(value);
    digitalWrite (green,HIGH);
    digitalWrite (red,LOW);
    digitalWrite(blue,LOW);
    noTone(buzzer);
  }
  else if (value > 680) 
  {
    Serial.print("Water Level:HIGH->");
    Serial.println(value);
    digitalWrite (red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(blue,LOW);
    tone(buzzer, 1000); 
  }
  delay(1000);
}
