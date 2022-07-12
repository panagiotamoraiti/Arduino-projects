//Read numbers from serial monitor.
void setup() 
{
  Serial.begin(9600);//serial communication.

}

void loop() 
{
  int x;
  if(Serial.available())//if there are characters we want to read.
  {
    char c=Serial.read();//Read a char.
    if(c=='\n')
    {
      //Do nothing.
    }
    else if((c>='0') && (c<='9'))
    {
      x=c-'0';//we find the real value of the number.
      //converting char value to number value.
      //Commands using integer x.
    }
  }

}
