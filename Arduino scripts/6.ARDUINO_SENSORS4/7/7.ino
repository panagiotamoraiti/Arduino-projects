int pd=2;//Photodiode-Black led
int led=13;//RED LED to digital pin 7  
int senRead=A0;//Readings from sensor to analog pin A0-White led
int limit = 1000;

void setup()    
{  
  pinMode(pd,OUTPUT);  
  pinMode(led,OUTPUT);  
  digitalWrite(pd,HIGH);//supply 5 volts to photodiode  
  digitalWrite(led,LOW);    
  Serial.begin(9600);         
}  
 
void loop()  
{  
  int val=analogRead(senRead);//photodiode reading
  Serial.println(val);      
  if(val >= limit)//If obstacle is nearer than the Threshold range  
  {  
   digitalWrite(led,HIGH);// LED opens
   Serial.println("Obstacle detected!");
   delay(20);  
  }  
  else if(val < limit)//If obstacle is not in Threshold range  
  {  
   digitalWrite(led,LOW);//LED closes
   delay(20);  
  }  
}  
