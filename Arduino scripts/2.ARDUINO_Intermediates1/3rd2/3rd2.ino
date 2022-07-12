#define led 12
#define button 13

bool button_state=1;//HIGH.
  
void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() 
{
  button_state = digitalRead(button);//WE READ THE BUTTONS'S VALUE.
  /*if(button_state==HIGH)//NOT PRESSED.
  {
    digitalWrite(led, LOW);
  }
  else//PRESSED.
  {
    digitalWrite(led, HIGH);
  }
  delay(1000);*/

  //2nd way.
  button_state = digitalRead(button);//WE READ THE BUTTONS'S VALUE.
  digitalWrite(led, !button_state);
  delay(1000);
}
