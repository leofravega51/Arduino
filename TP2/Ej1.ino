#define trigPin  9
#define echoPin  8
#define redPin 7
long duration, cm, inches;

void setup()
{
  Serial.begin(9600);
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



void loop()
{
  cm = ping(trigPin, echoPin);
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(250);
  
  if(cm<5){
    digitalWrite(redPin, HIGH);
    
  }else{
    digitalWrite(redPin, LOW);
  }
  
}