/*
Modifique el ejercicio uno, para que luego de tres movimientos, lea la posición en la que
quedo y la muestre por consola, y luego realice los siguiente movimientos 0, 180 y 90
grados y luego continúe.
*/

#include <Servo.h>
 
//Declare variable to control servo motor
Servo servoMotor;
long randNumber;
byte i;
 
void setup() {
  
  Serial.begin(9600);
 
  // Initialize servo to work on pin 9
  servoMotor.attach(9);
}
 
void loop() {
  
  for(i=1; i<=3;i++){
  	randNumber = random(181);
  
    //We move the servo to position randNumber (0-180)
    servoMotor.write(randNumber);
    //Delay of 1 second
    delay(1000);
  }
  
  //Read the servo value and print
  Serial.println(servoMotor.read());
  //Delay of 1 second
  delay(1000);
  
  //We move the servo to position 0°
    servoMotor.write(0);
    //Delay of 1 second
    delay(1000);
  
  //We move the servo to position 180°
    servoMotor.write(180);
    //Delay of 1 second
    delay(1000);
  
  //We move the servo to position 90°
    servoMotor.write(90);
    //Delay of 1 second
    delay(1000);
}