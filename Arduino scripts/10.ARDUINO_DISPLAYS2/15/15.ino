#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7); //interfacing pins

#define btnNONE 0
#define btnRIGHT 1
#define btnUP 2
#define btnDOWN 3
#define btnLEFT 4
#define btnSELECT 5

void setup()
{
  pinMode(10, INPUT);
  pinMode(A0, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  delay(500);
}

void loop()
{
  readkeypad();
  delay(50);
}

int readkeypad()
{
  int key = analogRead(A0);
  if(key<60)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RIGHT");
  }
  else if(key<200)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("UP");
  }
  else if(key<400)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DOWN");
  }
  else if(key<600)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LEFT");
  }
  else if(key<800)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SELECT");
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NONE");
  }
}
