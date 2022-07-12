#define red 9
#define green 10
#define blue 11

void setup() 
{
  Serial.begin(9600);//we begin serial communication.
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() 
{
  String command = Serial.readStringUntil('\n');
  if(command == "red")
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  }
  else if(command == "green")
  {
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
  }
  else if(command == "blue")
  {  
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
  }
  else
  {
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  }
    /*char str[10];
    int i;
    for(i=0; i<Serial.available(); i++)//We read the word.
    {
      str[i]=Serial.read();
    }*/

    /*if(i>0)//There is a word.
    {
      str[i]='\0';// \0 terminates the string.
      
      if((String)str == "red")
      {
        digitalWrite(red,HIGH);
        digitalWrite(green,LOW);
        digitalWrite(blue,LOW);
      }
      else if((String)str == "green")
      {
        digitalWrite(red,LOW);
        digitalWrite(green,HIGH);
        digitalWrite(blue,LOW);
      }
      else if((String)str == "blue")
      {
        digitalWrite(red,LOW);
        digitalWrite(green,LOW);
        digitalWrite(blue,HIGH);
      }
      else
      {
        digitalWrite(red,LOW);
        digitalWrite(green,LOW);
        digitalWrite(blue,LOW);
      }
    }
    for(int i=0;i<sizeof(str);i++){
    Serial.println(str[i]);}*/
    delay(1000);
}
    
