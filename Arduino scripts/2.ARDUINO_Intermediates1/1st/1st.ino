bool led_state=0;

void setup() 
{
  pinMode(13,OUTPUT);
}

void loop() 
{
  digitalWrite(13,led_state);//CONTROL THE LED.
  led_state=!led_state;
  delay(1000);//WAIT 1SEC.
}
