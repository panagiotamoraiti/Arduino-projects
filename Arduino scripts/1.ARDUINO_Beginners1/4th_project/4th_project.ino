bool led_state=1;//HIGH
bool last_button_state=0;//LOW
bool button_state=0;//LOW
  
void setup() 
{
  pinMode(2,OUTPUT);
  pinMode(13,INPUT);
}

void loop() 
{
  button_state = digitalRead(13);//WE READ THE BUTTONS'S VALUE.
  if(last_button_state==LOW && button_state==HIGH)//IF THE button_state CHANGES.
  {
    led_state=!led_state;//WE CHANGE THE LED'S STATE.
    digitalWrite(2,led_state);
  }
  last_button_state=button_state;
}
