bool button_state=0;
bool last_button_state=0;
bool led_state=1;

void setup() 
{
  pinMode(11,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(2,INPUT);
}
void loop() 
{
  int x=analogRead(A2);//READ THE POTENTIOMETER VALUE.
  x=x/4;//CONVERT VALUE FROM 1024 TO 255.
  
  button_state=digitalRead(2);//READ THE BUTTON'S STATE.
  if(button_state==HIGH && last_button_state==LOW)//BUTTON STATE HAS CHANGED.
  {
    led_state=!led_state;//LED'S STATE CHANGES.
  }

  if(led_state==HIGH)//LED IS OPENED.
    {
      analogWrite(11,x);//OPEN THE LED IN THE ANALOG VALUE X THAT WE TOOK FROM THE POTENTIOMETER.
    }
    else//LED IS CLOSED.
    {
      analogWrite(11,LOW);//CLOSE THE LED.
    }

    last_button_state=button_state;
}
