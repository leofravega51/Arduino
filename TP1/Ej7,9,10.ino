#define trigPin  9
#define echoPin  8
#define redPin 6
#define bluePin 5
#define greenPin 3

long duration, cm, inches;
 
void setup() {
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
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

void Ejercicio7()
{
  cm = ping(trigPin, echoPin);
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(250);
}

void Ejercicio9()
{
  cm = ping(trigPin, echoPin);
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(250);

  if(cm<5){
    analogWrite(redPin, 255);
    delay(250);
  } else if(cm<10){
    analogWrite(redPin, 100);
    delay(250);
  } else if(cm<25){
    analogWrite(redPin, 10);
    delay(250);
  } else{
    analogWrite(redPin, 0);
    delay(250);
  }
  
 
}

void Ejercicio10(){
  cm = ping(trigPin, echoPin);
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(250);

  if(cm<5){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    delay(250);
  } else if(cm<10){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 20);
    delay(250);
  } else if(cm<25){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 233);
    delay(250);
  } else{
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(250);
  }
}
 
void loop()
{
  //Ejercicio7();
  //Ejercicio9();
  //Ejercicio10();
}