#define PIRPin 2
#define redPin 13
#define bluePin 12
int PIRValue;

void setup()
{
  Serial.begin(9600);
  //Define all pins
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(PIRPin, INPUT);
}

void loop()
{
  PIRValue = digitalRead(PIRPin);
  Serial.println(PIRValue);
  
  if (PIRValue == HIGH) {     
    digitalWrite(redPin, HIGH);
    delay(500);
    digitalWrite(redPin, LOW);
    delay(500);
  } 
  else {
    digitalWrite(bluePin, HIGH);
    delay(500);
    digitalWrite(bluePin, LOW);
    delay(500);
  }
}