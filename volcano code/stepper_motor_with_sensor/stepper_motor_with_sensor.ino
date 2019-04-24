/* 
  IR Breakbeam sensor demo!
*/
#include <Servo.h>

Servo wandDipper;  // name our servo

int wandDipperPos = 0;  // initialize variable for wandDipper's position
int wandDipperPin = 10; // wandDipper's wire on 'duino
int delayTimeInc = 30; //delay time for each move of one degree in ms
int delayTimeEnd = 1500; // delay time once servo reaches 180 degrees to allow time for bubbles to be blown

#define SERVOPIN 10

#define SENSORPIN 4

// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

void setup() {
   pinMode(SERVOPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  
  Serial.begin(9600);
  wandDipper.attach(wandDipperPin);  // attaches
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
 // Serial.println(wandDipperPos);
  
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn LED on:
    for (wandDipperPos = 0; wandDipperPos <= 180; wandDipperPos += 1) { // servo rotates from 0 to 180 degrees in increments of one degree
    wandDipper.write(wandDipperPos);              // servo will move to wandDipperPosition specified by variable wandDipperPos
  }
  
  delay(delayTimeEnd); //wait for bubbles to be blown by fan
  
  for (wandDipperPos = 180; wandDipperPos >= 0; wandDipperPos -= 1) { // servo rotates from 180 to 0 degrees in increments of one degree
    wandDipper.write(wandDipperPos);              // servo will move to wandDipperPosition specified by variable wandDipperPos
  }
  } 
  
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
  }
  lastState = sensorState;

}
