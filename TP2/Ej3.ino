#define redPin 4
#define LDRPin A0
int luz;

void setup()
{
  pinMode(redPin, OUTPUT); 
  pinMode(LDRPin, INPUT);
  Serial.begin(9600);
} 

void loop()
{
  // leemos el valor de la entrada analogica donde tenemos el LDR y lo guardamos en la variable luz
  luz = map(analogRead(LDRPin), 0, 1023 , 1 ,6); 
  Serial.println(luz);
  
  if(luz < 3){
    digitalWrite(redPin, HIGH);
    delay(733);
    digitalWrite(redPin, LOW);
  } else{
    digitalWrite(redPin, LOW);
  }


}