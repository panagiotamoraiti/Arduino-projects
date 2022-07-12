#define red 9
#define green 10
#define blue 11

void setup() 
{
  Serial.begin(9600);//we begin serial communication.
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() 
{
  if(Serial.available())//There are characters to read.
  {
    char c=Serial.read();
    if(c=='\n')
    {
      //do nothing.
    }
    else if(c=='r')//red.
    {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    }
    else if(c=='b')//blue.
    {
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
    }
    else if(c=='g')//green.
    {
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
    }
    else//other letter.
    {
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    }
  }
}
