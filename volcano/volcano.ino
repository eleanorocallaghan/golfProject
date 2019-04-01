#include <Servo.h>

Servo servoBoi;  // name our servo

int pos = 0;  // initialize variable for servo's position
int servoPin = 9; // servo's wire on 'duino
int delayTimeInc = 30; //delay time for each move of one degree in ms
int delayTimeEnd = 1000; // delay time once servo reaches 180 degrees to allow time for bubbles to be blown

void setup() {
  Serial.begin(9600);
  servoBoi.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // servo rotates from 0 to 180 degrees in increments of one degree
    servoBoi.write(pos);              // servo will move to position specified by variable pos
    delay(delayTimeInc);                       // waits 15ms for the servo to reach the position
    Serial.println(pos);
  }
  
  delay(delayTimeEnd); //wait for bubbles ot be blown by fan
  
  for (pos = 180; pos >= 0; pos -= 1) { // servo rotates from 180 to 0 degrees in increments of one degree
    servoBoi.write(pos);              // servo will move to position specified by variable pos
    delay(delayTimeInc);                       // waits 15ms for the servo to reach the position
    Serial.println(pos);
  }
}
