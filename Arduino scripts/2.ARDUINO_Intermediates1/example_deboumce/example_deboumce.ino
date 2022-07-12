//Debounce function.
//Debouncing time.
#define debounce_delay 50
#define button_pin 13

//Variables.
bool input_state=0;
bool last_input_state=0;
unsigned long last_debounce_time=0;

//Button value.
bool button_state=0;

//Debouncing function.
bool input_with_debounce()
{
  input_state=digitalRead(button_pin);//We read the input.
  if(input_state != last_input_state)//We need debouncing.
  {
    last_debounce_time=millis();
  }
  if((millis()-last_debounce_time)>debounce_delay)//WE don't need debouncing.
  {
    button_state=input_state;//we change the button_state.
  }
  last_input_state=input_state;
  
  return button_state;
}

//Example.
bool led_state=0;
bool last_button_state=1;
bool button=1;

#define led 12
//#define button_pin 13
  
void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
}

void loop() 
{
  button=!input_with_debounce();//WE READ THE BUTTONS'S VALUE.
  if(last_button_state==LOW && button==HIGH)//IF THE button_state CHANGES.
  {
    led_state=!led_state;//WE CHANGE THE LED'S STATE.
    digitalWrite(led,led_state);
  }
  last_button_state=button;
}
