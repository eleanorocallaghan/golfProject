#define enable1 5 //L293D pin 1
#define input1 4  //L293D pin 2
#define input2 3  //L293D pin 7
#define potPin A0

int dirAndSpeed; //this will keep track of the direction and speed of the motor
int num = 255; //used when we want the motor to go full speed

int potValue; //value that is inputted for the direction and speed of motor

// the following variables are used in the code that makes the palm tree rotate every few seconds
unsigned int state = 0; //keeps track of whether the palm tree should be rotating or not
unsigned long lastTime = 0; //keeps track of the last time the palm tree started rotating or stopped rotating
unsigned long duration = 1000; //length of time that motor is off/on for, changes depending on state's value

#define SENSORPIN 2  //for beam break sensor
#define LEDPIN 13 //for waterfall LED strip


// variables for beam break sensor's state
int sensorState = 0, lastState=0;

void setup() {
  Serial.begin(9600);

  //set up the motor and potentiometer as outputs
  pinMode(enable1, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(potPin, INPUT_PULLUP);

  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
}

void loop() {
  
  potValue = analogRead(potPin); //read the value of the potentiometer, will be a value from 0 - 1023

  //Convert potValue into a value from -255 to +255
  dirAndSpeed = 0.5*potValue-255.;

  // read the state of the beam break sensor:
  sensorState = digitalRead(SENSORPIN);
  Serial.println(sensorState);

//the following loop is what makes the palm tree rotate periodically while still checking the beam break sensor
while (true)
{
  sensorState = digitalRead(SENSORPIN);
  if (lastTime + duration < millis()) //if a duration of time has passed since we last checked
  {
    lastTime = millis(); //set the new lastTime as the current time
    state = !state; //flip state to the opposite value
    Serial.println(state);
  }
  if (state == 1) //if the motor should be running
  {
    duration = 500; 
    Serial.print(dirAndSpeed);
    analogWrite(enable1, abs(num)); // set motor speed
    Serial.println("  CW");
    digitalWrite(input1, HIGH); //turn that baby on
    digitalWrite(input2, LOW);
  }
  if (state == 0) //if the motor shouldn't be running
  {
    duration = 7000;
    Serial.println( "off");
    digitalWrite(input1, LOW); //turn the motor off
    digitalWrite(input2, LOW);
  }
  if (sensorState == LOW) //if a ball breaks the beam
  {
  break; //leave this loop and go to the loop that runs after the beam is broken
  }
}

  
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) 
  {         
  Serial.print(dirAndSpeed);
  analogWrite(enable1, abs(num)); // set motor speed

      if (dirAndSpeed>0)
      {
        Serial.println("  CW");
        digitalWrite(input1, HIGH); //rotate clockwise
        digitalWrite(input2, LOW);
        digitalWrite(LEDPIN, HIGH); //turn LED strip on
        delay(40000); //this is how long the motor and LED will stay on for, should be plenty of time for ball to get to top
      }
      else
      {
        Serial.println("  CCW");
        digitalWrite(input1, LOW);  //rotate counter clockwise
        digitalWrite(input2, HIGH);
        digitalWrite(LEDPIN, HIGH); //turn LED strip on
        delay(40000); //this is how long the motor and LED will stay on for, should be plenty of time for ball to get to top
      }
    //turn motor and LED strip off after 40 seconds
    digitalWrite(LEDPIN, LOW);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);    
     
  }
  else { //if the sensor isn
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
  }
  
}
