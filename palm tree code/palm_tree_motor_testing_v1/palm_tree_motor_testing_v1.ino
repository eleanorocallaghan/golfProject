#define CW 10 //CW is defined as pin #7//

void setup() { //Setup runs once//

pinMode(CW, OUTPUT); //Set CW as an output//

}

void loop() { //Loop runs forever//

digitalWrite(CW,HIGH); //Motor runs clockwise//

}
