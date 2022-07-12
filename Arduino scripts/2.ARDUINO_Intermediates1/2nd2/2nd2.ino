#define led_pin 6//if we change the connection pin we will change only that line of code.

void setup() 
{
  pinMode(led_pin,OUTPUT);
  digitalWrite(led_pin, LOW);//Closed led.
}

boolean fadeamount = true;
int brightness = 0;//Led closed.

void loop() {
  // adjust brightness based on current direction
  if(fadeamount)//fadeamount==true.
  {
    //step=1.
    brightness += 1;//0 to 255.
    //brightness = brightness + 1;
  }
  else //fadeamount==false.
  {
    //step=-1.
    brightness -= 1;//255 to 0.
    //brightness = brightness - 1;
  }

  //Apply current light level.
  analogWrite(led_pin, brightness);

  //When get to full bright, turn around.
  if(255 == brightness) 
  {
    fadeamount = false;
  }
  // when get to full off, turn around
  if(brightness==0) {
    fadeamount = true;
  }  
  delay(10); 
}
