//Led is closed.
int brightness=0;
int fadeamount=1;//Step=1.
#define led_pin 6//if we change the connection pin we will change only that line of code.

void setup() 
{
  pinMode(led_pin,OUTPUT);
  digitalWrite(led_pin, LOW);//Closed led.
}

void loop() 
{
  analogWrite(led_pin, brightness);//Control led through brightness.
  brightness=brightness+fadeamount;//Change the brightness.
  //Led opens.
  //brightness = 0 to 255.
  //fadeamount=step=1.

  //Led closes.
  //brightness = 255 to 0.
  //fadeamount=step=-1.
  
  if(brightness<=0 || brightness>=255)//Out of bounds.
  {
    fadeamount=-fadeamount;//step=-1.
  }
  delay(20);//Wait 20msec.
}
