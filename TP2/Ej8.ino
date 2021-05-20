#define redPin 13
#define tiltPin 2
int tiltValue, n;

void setup()
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(tiltPin, INPUT);
}

void loop()
{
  tiltValue = digitalRead(tiltPin);
  Serial.println(tiltValue);
  
  if(tiltValue == LOW){
  	for(n=1; n<=10; n++){
      digitalWrite(redPin, HIGH);
      delay(500); // Wait for 1000 millisecond(s)
      digitalWrite(redPin, LOW);
      delay(500); // Wait for 1000 millisecond(s)
    }
  }
  delay(2000); //Delay for "reset" 
  
  
}