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

if(button_state==HIGH)//NOT PRESSED. 
{
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
} 
 else//PRESSED. 
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
} 

delay(500); 
}
