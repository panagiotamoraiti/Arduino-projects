#define button 9
#define buzzer 8
bool button_state=1;//HIGH.

void setup() 
{
   pinMode(buzzer, OUTPUT);
   pinMode(button, INPUT_PULLUP);
}

void loop() 
{
  button_state = digitalRead(button);//WE READ THE BUTTONS'S VALUE.
  if(button_state==HIGH)//NOT PRESSED.
  {
    noTone(buzzer);// Stop the sound.
  }
  else//PRESSED.
  {
    tone(buzzer, 1000); //1KHz sound.
  }
}
