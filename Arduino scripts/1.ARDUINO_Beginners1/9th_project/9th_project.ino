//read characters from serial monitor.
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  char c;
  int x=Serial.available();//x is the number of characters we want to read.
  Serial.print("Characters in buffer: ");
  Serial.println(x);
  if(x)//if x is not 0.
  {
    c=Serial.read();//Read a char.
    Serial.print("The character is: ");
    if(c=='\n')
    {
      Serial.println("Change line.");
      //Do nothing.
    }
    else
    {
      Serial.println(c);
      //Commands.
    }
  }
  delay(1000);
}
