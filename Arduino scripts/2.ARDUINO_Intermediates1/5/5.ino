char my_str[6];
void setup() 
{
    // an array big enough for a 5 character string
   Serial.begin(9600);
   my_str[0] = 'H'; // the string consists of 5 characters
   my_str[1] = 'e';
   my_str[2] = 'l';
   my_str[3] = 'l';
   my_str[4] = 'o';
   my_str[5] = 0; // 6th array element is a null terminator
   Serial.println(my_str);
   for(int i=0;i<sizeof(my_str);i++)
    {
      Serial.println(my_str[i]);
    }
}

void loop() 
{ 
}
    
