void setup() 
{
  pinMode(2,OUTPUT);
  pinMode(13,INPUT);
}

void loop() 
{
  int button_state = digitalRead(13);//WE READ THE BUTTONS'S VALUE.
  digitalWrite(2,button_state);//LED does what the button_state is(HIGH or LOW).
}
