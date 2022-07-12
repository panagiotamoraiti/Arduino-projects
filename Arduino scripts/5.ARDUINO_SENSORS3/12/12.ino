#include <dht.h>

#define DHT11_PIN 7
dht DHT;//we declare the object.

void setup()
{
  Serial.begin(9600);
}

void loop(){
  int value = DHT.read11(DHT11_PIN);//we read the sensor's value.
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);//temperature.
  Serial.print("C");
  Serial.print(" Humidity = ");
  Serial.print(DHT.humidity);//humidity.
  Serial.println("%");
  delay(2000);
}
