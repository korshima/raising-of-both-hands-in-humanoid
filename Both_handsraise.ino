#include <Servo.h>
//A program to demostrate raising of both hands 
// In this case the two servos from both hands are looped to the same pin on the arduino board
//By Korshima
unsigned long MOVING_TIME = 2000; // moving time is 2 seconds
unsigned long moveStartTime;
int startAngle = 0; // 0°
int stopAngle  = 180; // 180°

Servo myservo;  // create servo object to control a servo


int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(6);  // attaches the both servo of the two hands on pin 6 to the servo object
  moveStartTime = millis(); // start moving
}

void loop() {
  
  unsigned long progress = millis() - moveStartTime;

  if (progress <= MOVING_TIME) {
    long angle = map(progress, 0, MOVING_TIME, startAngle, stopAngle);
   //Servo myServo.write(angle); 
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
   
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2000);                       // waits 2secs for the servo to reach the position
  
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   
  
  }   }
  }
}
