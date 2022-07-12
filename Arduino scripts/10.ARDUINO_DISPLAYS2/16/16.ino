#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);  //interfacing pins

void setup() 
{
   lcd.begin(16, 2);
   delay(500);
}
void loop() 
{
  int key = analogRead(A0);
  
  if(key<800 && key>=600)//button select pressed.
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("                Arduino is great!!");
    
    for (int i = 0; i < 34; i++) 
    {
      lcd.scrollDisplayLeft();
      delay(400);  //Scrolling speed
    }
    delay(500);
    lcd.clear();
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print(" Have fun with  ");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("   Arduino!!!   "); 
    delay(50);
  }
} 
