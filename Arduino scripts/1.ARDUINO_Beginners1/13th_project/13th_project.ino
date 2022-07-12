#include <Servo.h>
Servo myservo;
void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() 
{
  int x=0;
  while(true)
  {
    if(Serial.available())
    {
      char c=Serial.read();
      if(c=='\n')
      {
        break;
      }
      else if((c>='0') && (c<='9') && (x!=-1))
      {
        x=10*x+(c-'0');
      }
      else
      {
        x=-1;
      }
    }
  }

  if(x<0 || x>180)
  {
    Serial.print("You entered: ");
    Serial.print(x);
    Serial.println(" degrees.");
    Serial.println("Wrong input!");
  }
  else
  {
    Serial.print("You entered: ");
    Serial.print(x);
    Serial.println(" degrees.");
    Serial.println("On the way!");
    myservo.write(x);
  }
}
