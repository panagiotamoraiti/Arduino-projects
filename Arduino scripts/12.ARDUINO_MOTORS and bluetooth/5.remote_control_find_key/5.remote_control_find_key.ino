#include <IRremote.h>

const int RECV_PIN = A3;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  //irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results))
  {
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;
        Serial.println(results.value, HEX);//print key at HEX system.         
  }
        key_value = results.value;
        irrecv.resume(); 
  }
