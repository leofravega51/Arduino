#define redLed 13
#define yellowLed 12
#define greenLed 11
#define potenciometro A0
byte randNum;
int brillo;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

void turnOnLed(byte led, short time)
{
  digitalWrite(led, HIGH);
  delay(time);
}

void turnOffLed(byte led, short time)
{
  digitalWrite(led, LOW);
  delay(time);
}

void Ejercicio1()
{
  turnOnLed(greenLed, 2000); //Turn the led on for 2000 milliseconds
  turnOffLed(greenLed, 0); //Turn the led off for 2000 milliseconds

  turnOnLed(yellowLed, 2000); //Turn the led on for 2000 milliseconds
  turnOffLed(yellowLed, 0); //Turn the led off for 2000 milliseconds
  
  turnOnLed(redLed, 2000); //Turn the led on for 2000 milliseconds
  turnOffLed(redLed, 0); //Turn the led off for 2000 milliseconds

}

void Ejercicio2()
{
  randNum = random(11);
  Serial.println(randNum);
  
  switch (randNum) {
    case 0:
    case 2:
    case 8:
      //Turn ON greenLed
      turnOnLed(greenLed, 2000);
      break;
    case 1:
    case 3:
    case 7:
      //Turn ON redLed
      turnOnLed(redLed, 2000);
      break;
    case 4:
    case 5:
    case 9:
      //Turn ON yellowLed
      turnOnLed(yellowLed, 2000);
      break;
    case 10:
      //Turn OFF all Leds
      turnOffLed(greenLed, 0);
      turnOffLed(yellowLed, 0);
      turnOffLed(redLed, 0);
      delay(2000);
      break;
	}
}

void Ejercicio4()
{
  brillo = analogRead (potenciometro)/4;
  
  analogWrite(greenLed, brillo);
}


void loop()
{
  //Ejercicio1();
  //Ejercicio2();
  //Ejercicio4();
}