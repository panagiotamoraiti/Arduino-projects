#define red 9
#define green 10
#define blue 11

void setup() 
{
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() 
{
  //RED
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  delay(1000);
  //GREEN
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
  delay(1000);
  //BLUE
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  delay(1000);

  //CLOSED LED
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  delay(1000);
  //ORANGE
  digitalWrite(red,HIGH);
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
  delay(1000);
  //CLOSED LED
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  delay(1000);
  //PINK
  analogWrite(red,1255);
  analogWrite(green,0);
  analogWrite(blue,255);
  delay(1000);
  //CLOSED LED
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  delay(1000);
}
