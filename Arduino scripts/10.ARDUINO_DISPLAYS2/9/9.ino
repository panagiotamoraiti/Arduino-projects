#include <SevSeg.h>
SevSeg sevseg; 
const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {10, 9, 8, 7, 6, 5, 4, 3};
    bool resistorsOnSegments = true;
 
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  delay(30);
  
  if (buttonState == LOW) 
  {
    sevseg.refreshDisplay(); 
    sevseg.setNumber(random(0,10));
  }
}
