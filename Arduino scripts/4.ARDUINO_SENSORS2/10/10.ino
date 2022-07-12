int relay_pin = 8;
int led_pin = 13;

void setup(){ 
  pinMode(relay_pin,OUTPUT);
  pinMode(led_pin,OUTPUT);  
  digitalWrite(led_pin,HIGH);//the led pin is HIGH.
}

void loop(){
  digitalWrite(relay_pin,HIGH);//relay signal.
  delay(1000);
  digitalWrite(relay_pin,LOW);//relay signal.
  delay(1000);
}
