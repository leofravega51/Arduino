#define redPin 6
#define bluePin 5
#define greenPin 3
#define puls 2
long redRandom, blueRandom, greenRandom;


void setup()
{
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(puls, INPUT);
}

void loop()
{
  Serial.println(digitalRead(puls));
  if (digitalRead(puls) == HIGH) {
    //Generate random numbers from 0-255 for a random rgb color
    redRandom = random(256);
    blueRandom = random(256);
    greenRandom = random(256);
    
    analogWrite(redPin, redRandom);
    analogWrite(bluePin, blueRandom);
    analogWrite(greenPin, greenRandom);
    delay(2000); //Turn on rgb random color for 2 seconds
  }
  else {
    //Turn off rgb
    analogWrite(redPin, 0);
    analogWrite(bluePin, 0);
    analogWrite(greenPin, 0);
  }
}