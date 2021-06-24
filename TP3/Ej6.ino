#define trigPin  9
#define echoPin  8
#define buzzer 5

long duration, cm;

/*
Utilizando un buzzer y un ultrasónico hc-sr04, realizar un pequeño bip variando su de
acuerdo a la distancia que se detecten los objetos:
a. Si la distancia esta entre 20 cm y 30 cm el bip debe realizarse cada 1500 mseg
b. Si la distancia esta entre 12 cm y 20 cm el bip debe realizarse cada 1 segundo
c. Si la distancia esta entre 6 cm y 12 cm el bip debe realizarse cada 500 mseg
d. Si la distancia esta entre 2 cm y 6 cm el bip debe realizarse cada 250 mseg
e. Fuera de esos rango no debe emitir sonido
*/


void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
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
  
  if((cm>=2)&&(cm<6)){
    analogWrite(buzzer, HIGH);
    delay(100);
    analogWrite(buzzer, LOW);
    delay(250);        
  }
  else if((cm>=6)&&(cm<12)){
    analogWrite(buzzer, HIGH); 
    delay(100);
    analogWrite(buzzer, LOW);
    delay(500);
  }
  else if((cm>=12)&&(cm<20)){
  	analogWrite(buzzer, HIGH);   
    delay(100);
    analogWrite(buzzer, LOW);
    delay(1000);
  }
  else if((cm>=20)&&(cm<30)){
  	analogWrite(buzzer, HIGH);
   	delay(100);
    analogWrite(buzzer, LOW);
    delay(1500);
  }
  else{       
    analogWrite(buzzer, LOW);
  }
  
  
}