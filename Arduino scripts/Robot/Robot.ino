//1 Remote_control_car
//2 arduino_car_bluetooth
//3 control_led_with_Bluetooth
//4 line_follower_car  
//5 stop

#include <AFMotor.h>
#include <IRremote.h>

const int RECV_PIN = A3;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
bool flag5 = false;

//1 Remote_control_car
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//3
#define led 13

//4
#define Left_sensor A1
#define Right_sensor A2
int threshold = 100;


void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  //irrecv.blink13(true);

  //1 Remote_control_car
  //Set initial speed of the motor & stop
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  //3
  pinMode(led, OUTPUT);

  //4
  pinMode(Right_sensor, INPUT); 
  pinMode(Left_sensor, INPUT);
}

void loop() 
{
  if (irrecv.decode(&results))
  {
    if (results.value == 0XFFFFFFFF)
    results.value = key_value;
    delay(100);
    //Serial.println("start");      
    //Serial.println(results.value, HEX);
    if(results.value == 0XFFA25D)//1
    {
      flag1 = true;
      flag2 = false;
      flag3 = false;
      flag4 = false;
      flag5 = false;
      Serial.println("1 Remote_control_car");
    }
    else if(results.value == 0XFF629D)//2
    {
      flag1 = false;
      flag2 = true;
      flag3 = false;
      flag4 = false;
      flag5 = false; 
      Serial.println("2 arduino_car_bluetooth");
    }
    else if(results.value == 0XFFE21D)//3
    {
      flag1 = false;
      flag2 = false;
      flag3 = true;
      flag4 = false;
      flag5 = false;
      Serial.println("3 control_led_with_Bluetooth");
    }
    else if(results.value == 0XFF22DD)//4
    {
      flag1 = false;
      flag2 = false;
      flag3 = false;
      flag4 = true;
      flag5 = false;
      Serial.println("4 line_follower_car ");
    }
    else if(results.value == 0XFF02FD)//5
    {
      flag1 = false;
      flag2 = false;
      flag3 = false;
      flag4 = false;
      flag5 = true;
      Serial.println("5 stop");
    }
    delay(50);              
  }
  key_value = results.value;
  irrecv.resume(); 
  delay(100);

  //1 Remote_control_car
  if(flag1)
  {
    uint8_t i;
    if (irrecv.decode(&results))
    {
      if (results.value == 0XFFFFFFFF)
      results.value = key_value;
      delay(100);
            
      //Serial.println(results.value, HEX);
      if(results.value == 0XFF18E7)//Forward.
      {
        motor1.run(FORWARD); 
        motor2.run(FORWARD); 
        motor3.run(FORWARD);
        motor4.run(FORWARD); 
        Serial.println("FORWARD");
      }
      else if(results.value == 0XFF4AB5)//Backward.
      {
        motor1.run(BACKWARD); 
        motor2.run(BACKWARD); 
        motor3.run(BACKWARD);
        motor4.run(BACKWARD); 
        Serial.println("BACKWARD");
      }
      else if(results.value == 0XFF5AA5)//Right.
      {
        motor1.run(FORWARD); 
        motor2.run(FORWARD); 
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        Serial.println("Right");
      }
      else if(results.value == 0XFF10EF)//Left.
      {
        motor1.run(BACKWARD); 
        motor2.run(BACKWARD); 
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        Serial.println("Left");
      }
      else if(results.value == 0XFF38C7)//Stop.
      {
        motor1.run(RELEASE); 
        motor2.run(RELEASE); 
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        Serial.println("Stop");
      }
      delay(50);              
    }
    key_value = results.value;
    irrecv.resume(); 
    delay(100);
  }

  //2 arduino_car_bluetooth
  if(flag2)
  {
    uint8_t i;
    if(Serial.available())
    {
      char c = Serial.read();
      Serial.println(c);
      if(c == '1')
      {
        motor1.run(FORWARD); 
        motor2.run(FORWARD); 
        motor3.run(FORWARD);
        motor4.run(FORWARD); 
        Serial.println("FORWARD");
      }
      else if(c == '2')
      {
        motor1.run(BACKWARD); 
        motor2.run(BACKWARD); 
        motor3.run(BACKWARD);
        motor4.run(BACKWARD); 
        Serial.println("BACKWARD");
      }
      else if(c == '3')
      {
        motor1.run(BACKWARD); 
        motor2.run(BACKWARD); 
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        Serial.println("RIGHT");
      }
      else if(c == '4')
      {
        motor1.run(FORWARD); 
        motor2.run(FORWARD); 
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        Serial.println("LEFT");
      }
      else if(c == '5')
      {
        motor1.run(RELEASE); 
        motor2.run(RELEASE); 
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        Serial.println("STOP");
      }
      delay(50);
    } 
  }

  //3 control_led_with_Bluetooth
  if(flag3)
  {
    if(Serial.available())
    {
      char c = Serial.read();
      if(c == 'a')
      {
        digitalWrite(led, HIGH);
      }
      else if(c == 'b')
      {
        digitalWrite(led, LOW);
      }
      delay(50);
    }
  }

  //4 line_follower_car
  if(flag4)
  {
    uint8_t i;
    int LEFT_SENSOR = analogRead(Left_sensor);
    int RIGHT_SENSOR = analogRead(Right_sensor);

    if(RIGHT_SENSOR<threshold && LEFT_SENSOR<threshold)
    {
      //FORWARD
      motor1.setSpeed(140);
      motor2.setSpeed(140);
      motor3.setSpeed(140);
      motor4.setSpeed(140);
      motor1.run(FORWARD); 
      motor2.run(FORWARD);  
      motor3.run(FORWARD);
      motor4.run(FORWARD); 
    }
    else if(RIGHT_SENSOR>threshold && LEFT_SENSOR<threshold)
    {
      //LEFT
      motor1.setSpeed(200);
      motor2.setSpeed(200);
      motor3.setSpeed(200);
      motor4.setSpeed(200);
      motor1.run(FORWARD); 
      motor2.run(FORWARD); 
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);          
    }
    else if(RIGHT_SENSOR<threshold && LEFT_SENSOR>threshold)
    { 
      //RIGHT
      motor1.setSpeed(200);
      motor2.setSpeed(200);
      motor3.setSpeed(200);
      motor4.setSpeed(200);
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD); 
      motor3.run(FORWARD);
      motor4.run(FORWARD);             
    } 
    else if(RIGHT_SENSOR>threshold && LEFT_SENSOR>threshold)
    { 
      //Back
      motor1.setSpeed(140);
      motor2.setSpeed(140);
      motor3.setSpeed(140);
      motor4.setSpeed(140);
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD); 
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);           
    }
  }

  //5 stop
  if(flag5)
  {
    motor1.run(RELEASE); 
    motor2.run(RELEASE); 
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
}
