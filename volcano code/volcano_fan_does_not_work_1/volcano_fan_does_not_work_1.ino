#include <Servo.h>

Servo fanBlower; //name of motor that spins fan

int fanBlowerPos = 0; // initialize variable for fanBlower's position
int fanBlowerPin = 11; // fanBlower's wire on 'duino

void setup() {
  
   fanBlower.attach(fanBlowerPin, 1, 2);
  // fanBlower.attach(fanBlowerPin,1,2);
   Serial.begin(9600);
   fanBlower.writeMicroseconds(1);
   delay(2);
   fanBlower.writeMicroseconds(2);
   delay(2);
   fanBlower.writeMicroseconds(1);
   delay(1);
}

void loop() {

  fanBlower.writeMicroseconds(2);
   // fanBlower.write(2);
  
  Serial.println("hello");
    
}
