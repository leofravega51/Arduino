#define trigPin  9
#define echoPin  8
long cm;
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void printData(long cm, String msg)
{
  Serial.println(cm);
  Serial.println(msg);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distancia: ");
  lcd.print(cm);
  lcd.setCursor(0,1);
  lcd.print(msg);
  delay(1000);
} 

int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}

void loop() {
  cm = ping(trigPin, echoPin);
  if(cm < 5){
  	printData(cm, "Muy cerca");
  }else if(cm < 10){
  	printData(cm, "Cerca");
  }else if(cm < 25){
  	printData(cm, "Proximo");
  }else if(cm > 25){
  	lcd.clear();
  }
}
 