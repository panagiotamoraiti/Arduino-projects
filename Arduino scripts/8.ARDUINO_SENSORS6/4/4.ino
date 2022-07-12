#define buzzer 8

void setup() 
{
   pinMode(buzzer, OUTPUT);
   pinMode(2, INPUT_PULLUP); 
   pinMode(3, INPUT_PULLUP);
   pinMode(4, INPUT_PULLUP);
   pinMode(6, INPUT_PULLUP);
   pinMode(7, INPUT_PULLUP);
   pinMode(9, INPUT_PULLUP);
   pinMode(10, INPUT_PULLUP);
   pinMode(11, INPUT_PULLUP);
   pinMode(12, INPUT_PULLUP);
   pinMode(13, INPUT_PULLUP);
   Serial.begin(9600);
}

void loop() 
{
  int button_state1 = digitalRead(2);
  int button_state2 = digitalRead(3);
  int button_state3 = digitalRead(4);
  int button_state4 = digitalRead(6);
  int button_state5 = digitalRead(7);
  int button_state6 = digitalRead(9);
  int button_state7 = digitalRead(10);
  int button_state8 = digitalRead(11);
  int button_state9 = digitalRead(12);
  int button_state10 = digitalRead(13);

  Serial.println(digitalRead(8));

  if(button_state1==LOW)
  {
    tone(buzzer, 500); //500Hz
  }
  else if(button_state2==LOW)
  {
    tone(buzzer, 1000); //500Hz
  }
  else if(button_state3==LOW)
  {
    tone(buzzer, 1500); //500Hz
  }
  else if(button_state4==LOW)
  {
    tone(buzzer, 2000); //500Hz
  }
  else if(button_state5==LOW)
  {
    tone(buzzer, 2500); //500Hz
  }
  else if(button_state6==LOW)
  {
    tone(buzzer, 3000); //500Hz
  }
  else if(button_state7==LOW)
  {
    tone(buzzer, 3500); //500Hz
  }
  else if(button_state8==LOW)
  {
    tone(buzzer, 4000); //500Hz
  }
  else if(button_state9==LOW)
  {
    tone(buzzer, 4500); //500Hz
  }
  else if(button_state10==LOW)
  {
    tone(buzzer, 5000); //500Hz
  }
  else
  {
    noTone(buzzer);
  }
  //delay(100);
}
