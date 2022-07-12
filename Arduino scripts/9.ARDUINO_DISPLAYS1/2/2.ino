#include <dht.h> 
#include <LiquidCrystal.h> 
#define DHT11_PIN 7 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;//we declare the object.

void setup() 
{ 
  lcd.begin(16, 2);
} 

void loop()
{ 
  int value=DHT.read11(DHT11_PIN);
  lcd.setCursor(0, 0);
  lcd.print("Temp=");
  lcd.setCursor(5, 0);//cursor goes to 1st line, 5 column.
  lcd.print(DHT.temperature);
  lcd.setCursor(10, 0);//cursor goes to 1st line, 11 column.
  lcd.print("C");
  
  lcd.setCursor(0, 1);//cursor goes to 2nd line, 1st column.
  lcd.print("Humidity=");
  lcd.setCursor(9, 1);//cursor goes to 2nd line, 10 column.
  lcd.print(DHT.humidity);
  lcd.setCursor(14, 1);//cursor goes to 2nd line, 15 column.
  lcd.print("%");
  
  delay(2000); 
  lcd.clear();
 } 
