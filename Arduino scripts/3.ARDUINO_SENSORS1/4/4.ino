void setup() 
{
  pinMode(2,OUTPUT);//LED.
  pinMode(3,OUTPUT);//BUZZER.
  Serial.begin(9600);
}

void loop() 
{
  //ANALOG VALUE WE READ FROM THE SENSOR.
  float tempv=analogRead(A0);//0-1023.
  //WE CONVERT ANALOG VALUE TO VOLTS.
  float volts=(tempv/1023.0)*5.0;//0-5.
  //volts to mvolts
  float mv=volts*1000;
  //WE FIND THE TEMPERATURE.
  float temp=mv/10;//TEMPERATURE.
  Serial.print("sensor value: ");
  Serial.print(tempv);
  Serial.print(" ,");
  Serial.print("voltage: ");
  Serial.print(volts);
  Serial.print(" ,");
  Serial.print("temperature: ");
  Serial.print(temp);
  Serial.println(" Celsius.");
   
  if (temp>25.0)
  {
    //OPEN THE LED AND THE BUZZER.
    digitalWrite(2,HIGH);//LED OPENS.
    tone(3, 1000); //1KHz 
    delay(1000); 

  }
  else
  {
    digitalWrite(2,LOW);
    noTone(3);// Stop the sound. 
  }
  delay(500);
}
