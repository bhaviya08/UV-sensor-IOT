#include <SoftwareSerial.h>
#define trigPin 13
#define echoPin 12
#define led1 2

 
void setup() {
  BTserial.begin (38400);
  pinMode(trigPin, OUTPUT);//setting the sensor
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  
}
 
void loop() {
  long DURATION, DISTANCE;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // for delay
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  DURATION = pulseIn(echoPin, HIGH);
  DISTANCE = (DURATION/2) / 29.1;
  if (DISTANCE < 10) { 
    digitalWrite(led1,HIGH); 
  
}
  else {
    digitalWrite(led1,LOW);
    
  }
  if (DISTANCE >= 200 || DISTANCE <= 0){
    BTserial.println("NOT IN RANGE");
  }
  else {
    serial.print(DISTANCE);
    BTserial.println(" cm");
  }
  delay(500);
}
