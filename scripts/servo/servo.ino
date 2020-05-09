#include <Servo.h>// Importing the Servo lybrary
Servo MyServo;//Variable refering to the servo lybrary. It has all the function that the lybrary has.
int const PinPot = A0;//Connecting the potentiometer to an analog and creating the properly constant
int ValuePot;//Creating variable
int Angle;//Creating variable

void setup() {
  
 MyServo.attach(9);//Relating the servo to the pin 9
 Serial.begin(9600);//Initialting the serial port
 
}

void loop() {
  
 ValuePot = analogRead(PinPot);//Reading PinPot
 Angle = map(ValuePot,0,1023,0,179);//Changing the scale values
 Serial.print("PoS: ");//Showing the previous on the serial monitor
 Serial.print(ValuePot);
 Serial.print(", Angle: ");
 Serial.println(Angle);
 
 MyServo.write(Angle);
 delay(500);
 
}
