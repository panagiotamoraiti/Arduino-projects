#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  //lcd.clear();
 lcd.begin(16, 2);
 lcd.print("Hello World!");
 lcd.setCursor(0, 1);//cursor goes to 2nd line.
 lcd.print("Hello Panagiota!");
}

void loop()
{
  delay(5000);
  lcd.clear();
  lcd.setCursor(2, 0);//cursor goes to 1nd line, 3nd column.
  lcd.print("LCD Display!");
  lcd.setCursor(6, 1);//cursor goes to 2nd line, 7nd column.
  lcd.print("LCD!");
}
