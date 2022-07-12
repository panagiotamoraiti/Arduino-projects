void setup() 
{
  //LEDS.
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
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
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" Celsius.");
   
  if (temp<20.0 && temp>0)
  {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }
  else if(temp>20.0 && temp<22.0)
  {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }
  else if(temp>22.0 && temp<24.0)
  {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }
  else if(temp>24.0 && temp<26.0)
  {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
  }
  else if(temp>26.0 && temp<28.0)
  {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
  }
  delay(500);
}
