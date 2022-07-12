#include <AFMotor.h>
#include <IRremote.h>

const int RECV_PIN = A3;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() 
{
  Serial.begin(9600);
  //Set initial speed of the motor & stop
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  irrecv.enableIRIn();
  //irrecv.blink13(true);
}

void loop() 
{
  uint8_t i;

  if (irrecv.decode(&results))
  {
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;
        delay(100);
          
    Serial.println(results.value, HEX);
    if(results.value == 0XFF18E7)//Forward.
    {
      motor1.run(FORWARD); 
      motor2.run(FORWARD); 
      motor3.run(FORWARD);
      motor4.run(FORWARD); 
    }
    else if(results.value == 0XFF4AB5)//Backward.
    {
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD); 
      motor3.run(BACKWARD);
      motor4.run(BACKWARD); 
    }
    else if(results.value == 0XFF5AA5)//Right.
    {
      motor1.run(FORWARD); 
      motor2.run(FORWARD); 
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    }
    else if(results.value == 0XFF10EF)//Left.
    {
      
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD); 
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    }
    else if(results.value == 0XFF38C7)//Stop.
    {
      motor1.run(RELEASE); 
      motor2.run(RELEASE); 
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
    delay(50);              
  }
        key_value = results.value;
        irrecv.resume(); 
        delay(100);
}
