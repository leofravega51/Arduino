#include <Servo.h>
 
//Declare variable to control servo motor
Servo servoMotor;
long randNumber;
 
void setup() {
  
  Serial.begin(9600);
 
  // Initialize servo to work on pin 9
  servoMotor.attach(9);
}
 
void loop() {
  
  randNumber = random(181);
  
  //We move the servo to position randNumber (0-180)
  servoMotor.write(randNumber);
  //Delay of 1 second
  delay(1000);
  Serial.println(randNumber);
}