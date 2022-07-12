#define buzzer 8

void setup() 
{
   pinMode(buzzer, OUTPUT);
}

void loop() 
{
  tone(buzzer, 500, 1000); //500Hz
  delay(1000);
  noTone(buzzer);// Stop the sound.
  //delay(1000);
  
  tone(buzzer, 1000); //1KHz
  delay(1000);
  noTone(buzzer);// Stop the sound.
  //delay(1000);
  
  tone(buzzer, 2000); //2KHz
  delay(1000);
  noTone(buzzer);// Stop the sound.
  //delay(1000);
  
  tone(buzzer, 3000); //3KHz
  delay(1000);
  noTone(buzzer);// Stop the sound.
  //delay(1000);
  
  tone(buzzer, 4000); //4KHz
  delay(1000);
  noTone(buzzer);// Stop the sound.
  //delay(1000);
}
