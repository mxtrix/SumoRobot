/*
 Robo Club Sumo Competition
 Workshop I - Ultrasonics
 
 This simple code will allow you to measure the distance
 to an object using your HC-SR04 Ultrasonic distance sensor
 and your Arduino.
 */

#define trigPin 12 // blue
#define echoPin 11 // green

void setup() {
  Serial.begin (9600);              // allows terminal access
  pinMode(trigPin, OUTPUT);         // set up pin to trigger
  pinMode(echoPin, INPUT);          // set up pin to receive echo
}

void loop() {
  int duration, distance;           // set up variables
  digitalWrite(trigPin, HIGH);      // start of trigger sequence
  delayMicroseconds(1000);          // delay 1ms
  digitalWrite(trigPin, LOW);       // complete trigger sequence
  duration = pulseIn(echoPin, HIGH);  // see: http://arduino.cc/en/Reference/pulseIn
  distance = (duration/2) / 29.1;  // calculate distance from time
                                   // Divide the time in half (because
                                   // the pulse travelled to the object
                                   // AND back again.
                                   // Then divide the time by 29.1 microseconds/cm
                                   // (the speed of sound).
  if (distance >= 200 || distance <= 0){  // remove out-of-bounds readings
    Serial.println("Out of range");
  }
  else {                           // print distance if valid
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);                      // wait before repeating process
}
