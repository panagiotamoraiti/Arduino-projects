#include <SevSeg.h>
SevSeg sevseg; //Initiate the object.

void setup() 
{
    //Set to 4 for four digit display
    byte numDigits = 4;

    //defines common pins while using multi-digit display.
    byte digitPins[] = {2, 3, 4, 5};
    //Defines arduino pin connections in order: A, B, C, D, E, F, G, DP.
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    bool resistorsOnSegments = false; 
    // variable above indicates that 4 resistors were placed on the digit pins.
    // set variable to 1 if you want to use 8 resistors on the segment pins.
    sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}
void loop() 
{
    sevseg.setNumber(1111,1);
    sevseg.refreshDisplay();
    //sevseg.setNumber(5679,2);
    //sevseg.refreshDisplay();
    //sevseg.setNumber(8888,3);
    //sevseg.refreshDisplay(); 
}
