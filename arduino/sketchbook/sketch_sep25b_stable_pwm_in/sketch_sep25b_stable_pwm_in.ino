// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.
const int numReadings = 15;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A1;
int led = 2;
int led2 = 3;
int led3 = 4;
//int servo = 9;
int DIS = 8; //Disable pin on HIP4081A

int val;    // variable to read the value from the analog pin
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode(DIS, OUTPUT);
    
  
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(5);
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  //readings[readIndex] = analogRead(inputPin);
  readings[readIndex] = val;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  //Serial.println(average);
  digitalWrite(led,average);
  
  //delay(1);        // delay in between reads for stability
  
   val = analogRead(inputPin);            // reads the value of the potentiometer (value between 0 and 1023) 
  // scale value default=1023 for analog, calibrate to 629 for led fade example
  val = map(val, 0, 629, 0, 255);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(average);                  // sets the servo position according to the scaled value 
  Serial.println(val);
  Serial.println(average);
  Serial.println("");
  digitalWrite(led, average);
  delay(15);                           // waits for the servo to get there 
  

if (val > 0)
{digitalWrite(DIS, HIGH);  //if the temperature is less than 37C, turn on the relay
digitalWrite(led3, HIGH);}       //LED indicator

else if (val < 0)
{digitalWrite(DIS, LOW);  //if the temperature is greater than 37C, turn the Heater off because it is too hot!
digitalWrite(led3, LOW);}

else if (analogRead(1) == LOW)  //check if thermistor is plugged in
{digitalWrite(DIS, LOW);  //if it isn't turn the Heater off!
digitalWrite(led3, LOW);}

}
