int LED = 13;
int obstaclePin = 8;
int hasObstacle = HIGH;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);
}
void loop() {
  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == LOW)
  {
    digitalWrite(LED, HIGH);
    Serial.println("Obstacle detected!");
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("");
  }
  delay(200);
}
