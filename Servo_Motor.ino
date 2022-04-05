#include <Servo.h>
int servoPin = 9;
int angle = 178;
Servo s;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  s.write(angle);
}
