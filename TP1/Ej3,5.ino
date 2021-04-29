#define redPin 6
#define bluePin 5
#define greenPin 3
#define potenciometro A0
#define potenciometro2 A1
#define ponteciometro3 A2
byte randNum;
int brillo;
int brillo2;
int brillo3;


void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void turnOffLed(byte led, short time)
{
  digitalWrite(led, LOW);
  delay(time);
}

void turnOnLed(byte led, short time)
{
  digitalWrite(led, HIGH);
  delay(time);
}

void cambiar_color(int num)
{ 
  switch (num) {
    case 1:
    	//Generate red color
        turnOnLed(redPin, 2000);
        turnOffLed(redPin,0);
    	break;
    case 2:
        //Generate green color
        turnOnLed(greenPin, 2000);
        turnOffLed(greenPin, 0);
    	break;
    case 3:
        //Generate blue color
        turnOnLed(bluePin, 2000);
        turnOffLed(bluePin, 0);
    	break;
    case 4:
      //Generate yellow color
      turnOnLed(redPin, 0);
      turnOnLed(greenPin, 0);
      delay(2000);
      turnOffLed(redPin, 0);
      turnOffLed(greenPin, 0);
    	break;
    case 5:
      //Generate violet color
      turnOnLed(redPin, 0);
      turnOnLed(bluePin, 0);
      delay(2000);
      turnOffLed(redPin, 0);
      turnOffLed(bluePin, 0);
    	break;
    case 6:
        //Generate light blue color
        turnOnLed(bluePin, 0);
        turnOnLed(greenPin, 0);
        delay(2000);
        turnOffLed(bluePin, 0);
        turnOffLed(greenPin, 0);
    	break;
    case 7:
        //Generate white color
        turnOnLed(redPin, 0);
        turnOnLed(bluePin, 0);
        turnOnLed(greenPin, 0);
        delay(2000);
        turnOffLed(redPin, 0);
        turnOffLed(bluePin, 0);
        turnOffLed(greenPin, 0);
        break;
    case 8:
    	break;
  }

}

void Ejercicio3()
{
  for(int i=1;i<=7;i++)
  {
    cambiar_color(i);
  }
}


void Ejercicio5()
{
  brillo = map(analogRead(potenciometro),0, 1023, 0, 255);
  brillo2 = map(analogRead(potenciometro2), 0, 1023, 0, 255);
  brillo3 = map(analogRead(ponteciometro3), 0 , 1023, 0, 255);
  
  analogWrite(greenPin, brillo);
  analogWrite(bluePin, brillo2);
  analogWrite(redPin, brillo3);
}

void loop()
{
  //Ejercicio3();
  Ejercicio5();
}