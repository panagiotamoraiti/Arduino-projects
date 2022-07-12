#define button 3
#define led1 4
#define led2 5
bool button_state=1;//HIGH.
 
void setup() 
{ 
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
pinMode(button, INPUT_PULLUP); 
} 

void loop() 
{ 
button_state = digitalRead(button);//WE READ THE BUTTONS'S VALUE. 
digitalWrite(led1, !button_state);
digitalWrite(led2, button_state);
delay(500); 
}
