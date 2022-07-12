#include <LiquidCrystal.h>
#include <NewPing.h> 
#define ECHO_PIN 8
#define TRIGGER_PIN 9 
#define MAX_DISTANCE 200 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
 lcd.begin(16, 2);
}

void loop()
{
  int x=sonar.ping_cm();//x is the distance in cm. 
  lcd.print("Distance: ");
  lcd.setCursor(9, 0);//cursor goes to 1st line, 10 column.
  lcd.print(x);
  lcd.setCursor(12, 0);//cursor goes to 1st line, 14 column.
  lcd.print("cm");
  delay(2000);
  lcd.clear();
}
