void setup() 
{
  pinMode(2,OUTPUT);
  pinMode(13,INPUT);
}

void loop() 
{
  int button_state = digitalRead(13);//WE READ THE BUTTONS'S VALUE.
  if(button_state==HIGH)//BUTTON PRESSED.
  {
    digitalWrite(2,HIGH);//LED OPENS.
  }
  else//BUTTON NOT PRESSED.
  {
    digitalWrite(2,LOW);//LED CLOSES.
  }
}
