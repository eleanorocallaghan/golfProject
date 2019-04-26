#define enable1 5 //L293D pin 1
#define input1 4  //L293D pin 2
#define input2 3  //L293D pin 7
#define potPin A0

//Motor leads go to L293D pins 3 and 6
//5V goes to L293D pin 16
//GND goes to L293D pins 4,5,12, or 13
//Motor voltage source goes to L293D pin 8 and ground

int dirAndSpeed;

int potValue;

#define SENSORPIN 2 //CHECKKKKKKKKKKKKKKK
#define LEDPIN 13


// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
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
  
  potValue = analogRead(potPin); //Will be a value from 0 - 1023

  //Convert potValue into a value from -255 to +255
  dirAndSpeed = 0.5*potValue-255.;

  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
  
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) { 
   
        
  Serial.print(dirAndSpeed);
  analogWrite(enable1, abs(dirAndSpeed)); // set motor speed

      if (dirAndSpeed>0)
      {
        Serial.println("  CW");
        digitalWrite(input1, HIGH);
        digitalWrite(input2, LOW);
        delay(28000);
      }
      else
      {
        Serial.println("  CCW");
        digitalWrite(input1, LOW);
        digitalWrite(input2, HIGH);
        delay(28000);
      }
      
      
      // turn LED on:
   
    digitalWrite(LEDPIN, HIGH);
    
    delay(3000);

    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    
    delay(2000);
    
    digitalWrite(LEDPIN, LOW); 
  }
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
  }
  
//  delay(200);

    //lastState = sensorState;
  
}
