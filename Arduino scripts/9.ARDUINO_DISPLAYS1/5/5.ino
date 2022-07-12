#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int s=0;
int m=0;
int h=0;

void setup()
{
  lcd.begin(16, 2);
}

void loop() 
{
  lcd.setCursor(0,0);//1st line.
  lcd.print("TIME");
  lcd.setCursor(0,1);//2nd line.
  
  s=s+1;
  
  if(h<10)
  {
    lcd.print("0");
    lcd.print(h);
  }
  else if(h>=10 && h<=11)
  {
    lcd.print(h);
  }
  else if(h==12) 
  {
    h=0;
    lcd.print("0");
    lcd.print(h);
  }

  if(m<10)
  {
    lcd.print(":0");
    lcd.print(m);
  }
  else if(m>=10 && m<=59)
  {
    lcd.print(":");
    lcd.print(m);
  }
  else if(m==60) 
  {
    m=0;
    h=h+1;
    lcd.print(":0");
    lcd.print(m);
  }
  
  if(s<10)
  {
    lcd.print(":0");
    lcd.print(s);
  }
  else if(s>=10 && s<=59)
  {
    lcd.print(":");
    lcd.print(s);
  }
  else if(s==60)
  {
    s=0;
    m=m+1;
    lcd.print(":0");
    lcd.print(s);
  }
  
  delay(1000);
  lcd.clear();
}
