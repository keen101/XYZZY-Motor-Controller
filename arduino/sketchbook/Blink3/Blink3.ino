/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 2;
int led2 = 3;
int led3 = 4;
int DIS = 8;
int motor1 = 5;
int motor2 = 6;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(DIS, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led3, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, HIGH);
  digitalWrite(led, HIGH);
  digitalWrite(DIS, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor1, LOW);
  delay(2000);               // wait for a second
  digitalWrite(led3, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(led2, HIGH);
  digitalWrite(led, LOW);
  digitalWrite(DIS, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor1, HIGH);
  delay(2000);               // wait for a second
}
