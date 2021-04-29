#define LEDPin 4
#define LDRPin A0

void setup()
{
  pinMode(LEDPin, OUTPUT); 
  pinMode(LDRPin, INPUT);
  Serial.begin(9600);
} 

void loop()
{
  // leemos el valor de la entrada analogica donde tenemos el LDR y lo guardamos en la variable luz
  int luz = map(analogRead(LDRPin), 1023 ,0, 0 ,100);  


  Serial.print("LUZ = "); 
  Serial.print(luz);
  Serial.println(" %");
}