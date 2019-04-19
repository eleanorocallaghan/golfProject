#include <Servo.h>
 
Servo esc;
int throttlePin = 0;
 
void setup()
{
esc.attach(9);
Serial.begin(9600);
esc.write(0);
delay(1000);
esc.write(179);
delay(2000);
esc.write(0);
}
 
void loop()
{
int throttle = analogRead(throttlePin);
throttle = map(throttle, 0, 1023, 0, 179);
esc.write(95);
Serial.println(throttle);
}
