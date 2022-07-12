const int red1 = 8;
const int yellow1 = 9;
const int green1 = 10;
const int red2 = 11;
const int yellow2 = 12;
const int green2 = 13;

void setup() 
{
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(yellow2, OUTPUT);
}

void loop() 
{
  //Traffic light 1 is green, 2 is red.
  digitalWrite(red2, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red1, HIGH);
  delay(1000);
  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);
  
  delay(10000);//10 sec

  //Traffic light 1 is yellow, 2 is red.
  digitalWrite(green1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red1, LOW);

  delay(1500);//1.5 sec

  //Traffic light 2 is green, 1 is red.
  digitalWrite(red2, HIGH);
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(red1, HIGH);
  delay(1500);
  digitalWrite(green2, HIGH);
  digitalWrite(red2, LOW);

  delay(10000);//10 sec

  //Traffic light 2 is yellow, 1 is red.
  digitalWrite(green1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, HIGH);
  digitalWrite(green2, LOW);
  digitalWrite(red1, HIGH);

  delay(1500);//1.5 sec

}
