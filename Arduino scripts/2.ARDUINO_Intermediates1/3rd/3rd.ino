bool led_state=0;//LOW
bool last_button_state=1;//HIGH
bool button_state=1;//HIGH

#define led 12
#define button 13
  
void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(led, LOW);
}

void loop() 
{
  button_state = digitalRead(button);//WE READ THE BUTTONS'S VALUE.
  if(last_button_state==HIGH && button_state==LOW)//IF THE button_state CHANGES.
  {
    led_state=!led_state;//WE CHANGE THE LED'S STATE.
    digitalWrite(led,led_state);
    //2nd way.
    //Connection to pwm pin.
    //analogWrite(led, led_state*255);//led_state=1->HIGH 
                                     //led_state=0->LOW
  }
  last_button_state=button_state;
}
