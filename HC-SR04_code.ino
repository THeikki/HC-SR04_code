#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

const int TRIGPIN = 9;
const int ECHOPIN = 10;
long duration;
float distance;
float speedToObject = 0.0343/2; // SPEED OF SOUND: (343 m/s / 1000 => 0.0343 cm/us) / 2 

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  // Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  getDistance();
  printSensorValue();
  delay(1000);
}

void printSensorValue() { 

  //Serial.println(distance);
  
  if (mySerial.available() > 0) {
     mySerial.print(distance); 
     mySerial.println();
  }
  
}

void getDistance() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  duration = pulseIn(ECHOPIN, HIGH);
  distance = duration * speedToObject;
}
