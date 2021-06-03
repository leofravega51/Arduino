#include <Servo.h>
 
//Declare variable to control servo motor
Servo servoMotor;
long potNumber;

#define potenciometro A0

 
void setup() {
  
  Serial.begin(9600);
 
  // Initialize servo to work on pin 9
  servoMotor.attach(9);
}
 
void loop() {
  
  potNumber = map(analogRead(potenciometro),0, 1023, 180, 0);
  
  //We move the servo with the potenciometro on potNumber (0-180)
  servoMotor.write(potNumber);
  
  Serial.println(potNumber);

}