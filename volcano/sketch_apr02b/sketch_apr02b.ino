#include <Servo.h>

Servo fanBlower; //name of motor that spins fan

int fanBlowerPos = 0; // initialize variable for fanBlower's position
int fanBlowerPin = 11; // fanBlower's wire on 'duino

void setup() {
  Serial.begin(9600);
  fanBlower.attach(fanBlowerPin);
}

void loop() {

  fanBlower.write(3;
  Serial.println("hello");
    
}
