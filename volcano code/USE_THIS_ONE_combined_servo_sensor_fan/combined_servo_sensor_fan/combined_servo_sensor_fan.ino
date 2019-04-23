#include <Servo.h>
 
Servo esc;
int throttlePin = 0;

Servo wandDipper;  // name our servo

int wandDipperPos = 0;  // initialize variable for wandDipper's position
int wandDipperPin = 10; // wandDipper's wire on 'duino
int delayTimeInc = 30; //delay time for each move of one degree in ms
int delayTimeEnd = 1500; // delay time once servo reaches 180 degrees to allow time for bubbles to be blown

#define SERVOPIN 13

#define SENSORPIN 4

// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

void setup()
{
esc.attach(9);
Serial.begin(9600);
esc.write(0);
delay(1000);
esc.write(179);

pinMode(SERVOPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup

  wandDipper.attach(wandDipperPin);  // attaches
}
 
void loop()
{
int throttle = analogRead(throttlePin);
throttle = map(throttle, 0, 1023, 0, 179);
esc.write(throttle);
Serial.println(throttle);

// read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
  
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
  
  // if (sensorState && !lastState) {
  //  Serial.println("Unbroken");
  //} 
  //if (!sensorState && lastState) {
  // Serial.println("Broken");
  //}
  //lastState = sensorState;
}
