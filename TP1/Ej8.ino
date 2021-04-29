#define redPin 6
#define bluePin 5
#define greenPin 3
#define LDRPin A0

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(LDRPin, INPUT);
  Serial.begin(9600);

}

void loop()
{
  int luz = map(analogRead(LDRPin),0 , 1023 , 0 ,255);
  analogWrite(redPin, luz);
  delay(50); 
}