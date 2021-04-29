#define redPin1 4
#define redPin2 3
#define flexPin A0
int resistorValue;

void setup()
{
  Serial.begin(9600);
  pinMode(redPin1, OUTPUT); 
  pinMode(redPin2, OUTPUT); 
  pinMode(flexPin, INPUT);
}

void loop()
{
  //230 es el valor obtenido al aplicar fuerza hasta los 180°
  //624 es el valor obtenido al no aplicar fuerza sobre el flex (0°)
  resistorValue = map(analogRead(flexPin), 230, 624, 0, 255);
  
  Serial.println(resistorValue);
  
  analogWrite(redPin1, resistorValue);
  analogWrite(redPin2, 255-resistorValue);
}