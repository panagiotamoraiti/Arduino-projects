//Read numbers from serial monitor.
void setup() 
{
  Serial.begin(9600);//serial communication.
}

void loop() 
{
  int x=0;
  while(true)//We stay in the loop until we have read the whole number.
  {
    if(Serial.available())//if there are characters we want to read.
    {
      char c=Serial.read();//Read a char.
      if(c=='\n')//We read the last character.
      {
        break;//exit the loop, we have read the input.
      }
      else if((c>='0') && (c<='9') && (x!=-1))
      {
        x=10*x+(c-'0');//We find the value of x.
      }
      else//Wrong input.
      {
        x=-1;
      }
    }
  }

  if(x==-1)//flag.
  {
    Serial.println("Wrong input.");
  }
  else
  {
    //Command using integer x.
  }
}
