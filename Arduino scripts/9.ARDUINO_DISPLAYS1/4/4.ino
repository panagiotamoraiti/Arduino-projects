#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  //Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);//Starting button.
  digitalWrite(8, HIGH);
  pinMode(9, INPUT_PULLUP);//Stop button.
  digitalWrite(9, HIGH);
}
 
void loop()
{
  double i=0;
  double a;
  double c;
  lcd.clear();
  lcd.print("Press start");
  delay(100);

  //if start button is pressed.
  if(digitalRead(8)==LOW)//Button1 is pressed.
  {
      lcd.clear();
      a=millis();//We calculate the time, from the starting of the program.

      //While stop button is not pressed we measure the time t and we print it.
      while(digitalRead(9)==HIGH)//Button2 is not pressed.
      {
        c=millis();//We calculate the time, from the pressing of the button.
        i=(c-a)/1000;//We convert the time from msec to sec.
        lcd.print(i);//We print the time.
        lcd.setCursor(7,0);//cursor to 1st line, 8th column.
        lcd.print("Seconds");//We print the "seconds" next to the time we measured.
        lcd.setCursor(0,0);//cursor to (0,0).
        //Serial.println(c);
        //Serial.println(a);
        //Serial.println(i);
        //Serial.println("----------");
        delay(100);
      }

      //if stop button is pressed we leave printed the time t while start button is not pressed.
      if(digitalRead(9)==LOW)//Button2 is pressed.
      {
        //.
        while(digitalRead(8)==HIGH)//Button1 is not pressed.
        {
          lcd.setCursor(0,0);
          lcd.print(i);
          lcd.setCursor(11,0);
          lcd.print("");
          lcd.setCursor(0,0);
          delay(100);
        } 
        //if start button is pressed, reset.
     }
  }
}
