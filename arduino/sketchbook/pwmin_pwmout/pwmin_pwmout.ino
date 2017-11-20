// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
 
int potpin = 1;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
//int val2;
int led = 2;
int led2 = 3;
int led3 = 4;
int DIS = 8; //Disable pin on HIP4081A
 
void setup() 
{ 
  Serial.begin(9600);
   myservo2.attach(5);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object 
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(DIS, OUTPUT);
  
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  // scale value default=1023 for analog, calibrate to 629 for led fade example
  val = map(val, 0, 629, 0, 255);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  Serial.println(val);
  //Serial.println("");
  //Serial.println(val2);
  digitalWrite(led, val);
  //delay(50);                           // waits for the servo to get there 


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
