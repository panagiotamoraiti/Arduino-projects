#include <Keypad.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

const byte ROWS = 4; //four rows.
const byte COLS = 4; //four columns.

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad.
byte colPins[COLS] = {10, 13, A0, A1}; //connect to the column pinouts of the keypad.

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int num_of_keys=0;

//We change these 2 lines.
const int password_length=11;//We change it.
char password[password_length+1] = "0123456789A";//Give the password you want.

char my_str[password_length+1] = "";

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.print("Give password: ");
  lcd.setCursor(0, 1);
  //cursor goes to 2nd line.
}
  
void loop()
{
  char key = keypad.getKey();//Read the key.
  
  //Print if key pressed
  if (key)
  {
    lcd.print(key);//print key at lcd.

    //Put the key in the array.
    my_str[num_of_keys] = key;
    num_of_keys++;
  }

if(num_of_keys==password_length)
  {
    delay(1000);
    lcd.clear();
    if(strcmp(my_str, password)==0)//password is correct!
    {
      Serial.println(my_str);
      
      lcd.print("Correct password");
      delay(3000);
      lcd.clear();
      lcd.print("Give password: ");
      lcd.setCursor(0, 1);
      //cursor goes to 2nd line.
      num_of_keys=0;
      //Clear the array.
      for(int i=0; i<password_length; i++)
      {
        my_str[i] = "";
      }
    }
    else
    {
      Serial.println(my_str);
      
      lcd.print("Wrong password");
      delay(3000);
      lcd.clear();
      lcd.print("Give password: ");
      lcd.setCursor(0, 1);
      //cursor goes to 2nd line.
      num_of_keys=0;
      //Clear the array.
      for(int i=0; i<password_length; i++)
      {
        my_str[i] = "";
      }
    }
  }
}
