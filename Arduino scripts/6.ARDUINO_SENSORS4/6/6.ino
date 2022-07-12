#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 10;
const int greenPin = 11;


void setup(){
  irrecv.enableIRIn();
//  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFF38C7: //Keypad button "5"
          digitalWrite(redPin, HIGH);
          delay(1000);
          digitalWrite(redPin, LOW);
          break;
           
          case 0xFF18E7: //Keypad button "2"
          digitalWrite(greenPin, HIGH);
          break;
          
          case 0xFF7A85: //Keypad button "3"
          digitalWrite(greenPin, LOW);
          break;
          }

        irrecv.resume(); 
    }
}
