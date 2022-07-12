int led = 9 ;//LED
int hallsensor = 8;//Hall sensor
int digitalVal; 

void setup ()
{
  pinMode(led, OUTPUT); 
  pinMode(hallsensor, INPUT); 
}

void loop ()
{
  digitalVal = digitalRead(hallsensor);
  if (digitalVal == LOW)//Magnetic field. 
  {
    digitalWrite (led, HIGH);
  }
  else
  {
    digitalWrite (led, LOW);//NO magnetic field. 
  } 
  delay(100);
}
