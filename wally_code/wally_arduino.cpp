#include <Adafruit_PWMServoDriver.h> 

 

// Wally Lozano Diaz 

// Modified: 4/10/2023 

 

//Sweep a servo from 0 to 90 degrees with a flex sensor attached to rotating arm. 

//The flex sensor data flows into the A0 pin which is taking voltage reading from  

//a simple volatge divider between a flex sensor and 47Kohm resistor. 

 

// Each sweep will be repeated 50 times 

// Sweep alpha: 0 to 90 degrees in 3 sec 

// Sweep beta: 0 to 60 degrees in 2 sec 

// Sweep gamma: 0 to 30 degrees in 1 sec 

 

#include <Servo.h> 

 

Servo myservo;  // create servo object to control a servo 

// twelve servo objects can be created on most boards 

 

// Variables 

int sensorPin = A0;   // select the input pin for the flex sensor data input 

int sensorValue = 0;  // variable to store the value coming from the sensor 

 

// Constants 

int pos = 0;    // variable to store the servo position 

int pos_min = 950; 

int pos_max = 1600; 

int incmnt = 10; 

int delayStart = 6000; 

int delayEnd = 3000; 

int delayInc = 30; 

 

// Calibration constants 

int pos_min_calib = 950; 

int pos_maxAlpha_calib = 1950; 

int pos_maxBeta_calib = 1600; 

int pos_maxGamma_calib = 1250; 

 

void setup() { 

 

  Serial.begin(9600); 

  myservo.attach(9); 

  //myservo.detach(); 

 

  //myservo.attach(9,pos_min,pos_max);  // attaches the servo on pin 9 to the servo object 

   

  pinMode(sensorPin, INPUT); 

   

} 

 

void loop() { 

   

//calibrate to set intial position at 0 degrees and final position at 90 degrees 

  //myservo.writeMicroseconds(pos_min_calib);              // tell servo to go to position in variable 'pos' 

  //myservo.writeMicroseconds(pos_maxAlpha_calib);              // tell servo to go to position in variable 'pos' 

  //myservo.writeMicroseconds(pos_maxBeta_calib);              // tell servo to go to position in variable 'pos' 

  //myservo.writeMicroseconds(pos_maxGamma_calib);              // tell servo to go to position in variable 'pos' 

 

 //set start position 

    myservo.writeMicroseconds(pos_min);              // tell servo to go to position in variable 'pos' 

    delay(delayStart);                    // waits xx ms for the servo reaches final the position 

 

//sweep loop from start to end 

  for (pos = pos_min; pos <= pos_max; pos += incmnt) { // goes from 0 degrees to 60 degrees on protractor 

 

    // if (pos == pos_min) { 

    //   delay(delayEnd);                    // waits xx ms for the servo reaches final the position 

    //   }    

 

    sensorValue = analogRead(sensorPin); 

    Serial.println(sensorValue); 

    myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos' 

    delay(delayInc);                      // waits xx ms for the servo to reach the position 

    } 

     delay(delayEnd);                    // waits xx ms for the servo reaches final the position 

 

// end of sweep 

  //  myservo.writeMicroseconds(pos_min);              // tell servo to go to position in variable 'pos' 

  //     delay(delayEnd);                    // waits xx ms for the servo reaches final the position 

 

  //  myservo.detach(); 

 

//sweep loop from end to start  

  // for (pos = pos_max; pos >= pos_min; pos -= incmnt) { // goes from 90 degrees to 0 degrees on protractor 

      

  //    if (pos == pos_max) { 

  //     delay(delayEnd);                     // waits xx ms for the servo reaches final the position 

  //     } 

 

  //   myservo.writeMicroseconds(pos);                    // tell servo to go to position in variable 'pos' 

  //  // delay(delayInc);                       // waits xx ms for the servo to reach the position 

 // } 

} 
