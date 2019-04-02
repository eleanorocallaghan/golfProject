#include <Servo.h>

Servo wandDipper;  // name our servo
Servo fanBlower; //name of motor that spins fan

int wandDipperPos = 0;  // initialize variable for wandDipper's position
int fanBlowerPos = 0; // initialize variable for fanBlower's position
int wandDipperPin = 9; // wandDipper's wire on 'duino
int fanBlowerPin = 11; // fanBlower's wire on 'duino
int delayTimeInc = 30; //delay time for each move of one degree in ms
int delayTimeEnd = 1000; // delay time once servo reaches 180 degrees to allow time for bubbles to be blown


void setup() {
  Serial.begin(9600);
  wandDipper.attach(wandDipperPin);  // attaches
  fanBlower.attach(fanBlowerPin);
}

void loop() {
  // wandDipper stuff
  for (wandDipperPos = 0; wandDipperPos <= 180; wandDipperPos += 1) { // servo rotates from 0 to 180 degrees in increments of one degree
    wandDipper.write(wandDipperPos);              // servo will move to wandDipperPosition specified by variable wandDipperPos
    delay(delayTimeInc);                       // waits for the servo to reach the wandDipperPosition
    Serial.println(wandDipperPos);
  }
  
  delay(delayTimeEnd); //wait for bubbles to be blown by fan
  
  for (wandDipperPos = 180; wandDipperPos >= 0; wandDipperPos -= 1) { // servo rotates from 180 to 0 degrees in increments of one degree
    wandDipper.write(wandDipperPos);              // servo will move to wandDipperPosition specified by variable wandDipperPos
    delay(delayTimeInc);                       // waits for the servo to reach the wandDipperPosition
    Serial.println(wandDipperPos);
  }

  //fanBlower stuff
  fanBlower.write(180);
    
}
