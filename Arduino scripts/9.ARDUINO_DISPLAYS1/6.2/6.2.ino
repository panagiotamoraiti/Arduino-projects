#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte smiley[8] = 
{
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte sad[8] =
{
0b00000,
0b00000,
0b01010,
0b00000,
0b00100,
0b00000,
0b01110,
0b10001
};

byte robot[8] =
{
0b00000,
0b00000,
0b01010,
0b00000,
0b00100,
0b00000,
0b01110,
0b00000
};

byte person[8] =
{
0b00000,
0b01110,
0b01110,
0b10100,
0b01110,
0b00101,
0b00100,
0b01010
};

byte square1[8] =
{
0b00000,
0b00000,
0b00000,
0b00000,
0b11111,
0b11111,
0b11111,
0b11111
};

byte square2[8] =
{
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111
};


void setup() 
{
  lcd.createChar(0, smiley);
  lcd.createChar(1, sad);
  lcd.createChar(2, robot);
  lcd.createChar(3, person);
  lcd.createChar(4, square1);
  lcd.createChar(5, square2);
  lcd.begin(16, 2);  
  lcd.print("Custom Character");
  
}

void loop() 
{
  lcd.setCursor(0, 1);
  lcd.write(byte(0));

  lcd.setCursor(2, 1);
  lcd.write(byte(1));

  lcd.setCursor(4, 1);
  lcd.write(byte(2));

  lcd.setCursor(6, 1);
  lcd.write(byte(3));
  
  lcd.setCursor(8, 1);
  lcd.write(byte(4));

  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  
}
