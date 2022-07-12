#include <IRremote.h>
const int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

#include <dht.h> 
#define DHT11_PIN 7 
dht DHT;
#include <NewPing.h> 
#define TRIGGER_PIN 10 
#define ECHO_PIN 11
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//We declare the object sonar. 
#include <Servo.h> 
#define SERVO_PIN 12
Servo myservo; 

bool flag=false;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(3, OUTPUT);//BLUE LED. 
  pinMode(4, OUTPUT);//RED LED.
  pinMode(6, OUTPUT);//GREEN LED. 
  pinMode(5, OUTPUT);//YELLOW LED. 
  pinMode(8, OUTPUT);//BUZZER. 
  pinMode(A2,INPUT); //Potentiometer.
  pinMode(A1,INPUT);//Τemperature sensor.
  pinMode(A3,INPUT);//Water-Rain sensor.
  pinMode(A5,INPUT);//Photoresistor.
  pinMode(2, INPUT_PULLUP); //Button.
  myservo.attach(SERVO_PIN);//Servo.
  pinMode(13, INPUT); //PIR sensor.

  irrecv.enableIRIn();
  //irrecv.blink13(true);
  myservo.write(0); 
} 
void loop() 
{ 
  //Temperature sensor, red led.
  float temperature_value=analogRead(A1);//0-1023.
  temperature_value=analogRead(A1);
  //WE CONVERT ANALOG VALUE TO VOLTS. 
  float volts=(temperature_value/1023.0)*5.0;//0-5.
  //volts to mvolts 
  float mv=volts*1000;
  //WE FIND THE TEMPERATURE. 
  float temp=mv/10;//TEMPERATURE.
  //Serial.print("sensor value: "); 
  //Serial.print(temperature_value); 
  //Serial.print(" ,"); 
  //Serial.print("voltage: "); 
  //Serial.print(volts); 
  //Serial.print(" ,"); 
  Serial.print("Linear Temperature: "); 
  Serial.print(temp); 
  Serial.println(" Celsius.");
  
  //Temperature and humidity sensor.
  int value=DHT.read11(DHT11_PIN);
  //we read the sensor's value. 
  Serial.print("Temperature = "); 
  Serial.print(DHT.temperature);
  //temperature. 
  Serial.print("C");
  Serial.print(" Humidity = "); 
  Serial.print(DHT.humidity);
  //humidity. 
  Serial.println("%"); 

  if (DHT.temperature>30.0) 
  { 
    digitalWrite(4,HIGH);//RED LED OPENS. 
  } 
  else 
  { 
    digitalWrite(4,LOW); 
  }

  //Photoresistor, blue led.
  int photoresistor_value = analogRead(A5);//Photoresistor.
  if(photoresistor_value<=640)
  {
    // 1024/2=512. 
    digitalWrite(3,HIGH); 
  } 
  else 
  { 
    digitalWrite(3,LOW); 
  } 
  
  //Potentiometer, green led.
  int potentiometer_value = analogRead(A2);//READ THE POTENTIOMETER VALUE.
  //Serial.println(potentiometer_value); 
  potentiometer_value = potentiometer_value/4;//CONVERT VALUE FROM 1023 TO 255.
  analogWrite(6, potentiometer_value);
  
  //Button, yellow led.
  int button_state = digitalRead(2);
  delay(50);
  if(button_state==LOW) 
  {
    digitalWrite(5,HIGH); 
    delay(50);
  } 
  else
  {
    digitalWrite(5,LOW);
    delay(50);
  }
  
  //Ultrasonic, buzzer.
  int distance = sonar.ping_cm();//distance is the distance in cm. 
  Serial.print("The distance is: "); 
  Serial.print(distance); 
  Serial.println(" cm."); 
  if(distance<=20)
  {
    digitalWrite(8,HIGH); 
    Serial.println("STOP!!!");
    delay(100);
  }
  else if(distance<=30)
  {
    digitalWrite(8,HIGH); 
    delay(200);
  }
  else if(distance<=50)
  {
    digitalWrite(8,HIGH); 
    delay(350);
  }

  //Servo motor, (Ultrasonic).
  /*int angle=distance;//angle is the distance in cm. Serial.print("The distance is: "); 
  //Serial.print(angle); 
  //Serial.println(" cm."); 
  //Serial.print("The angle is: "); 
  //Serial.print(angle); 
  //Serial.println(" cm."); 
  myservo.write(angle); */ 

  //Water sensor.
  int rain_value = analogRead(A3); 
  if (rain_value>10)
  {
    Serial.println("It rains!"); 
  }

  //PIR sensor, buzzer, yellow led.
  bool motion = digitalRead(13); 
  if(motion) 
  { 
    digitalWrite(8,HIGH);
    digitalWrite(5,HIGH);
    Serial.println("Motion detected!");
   } 
  else 
  { 
    digitalWrite(8,LOW); 
    digitalWrite(5,LOW);
    Serial.println("No Motion!");
  } 

  //IR SENSOR, Servo.
  if (irrecv.decode(&results))
  {
    switch(results.value)
    {
      case 0xFFA857: //Keypad button "+"
      myservo.write(180); 
      delay(500);
      flag=true;
    }

    switch(results.value)
    {
      case 0xFFE01F: //Keypad button "-"
      myservo.write(0); 
      delay(500);
      flag=false;
    }
    irrecv.resume(); 
  }

  if(flag==true)
  {
      Serial.println("The door is opened!");
  }
  else
  {
    Serial.println("The door is closed!");
  }

  Serial.println("");
  delay(1200);
}
