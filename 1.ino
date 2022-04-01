//Step 1: defining a program to sense a button read it and then turn on an led
//digitalRead works reverse i.e 1 when off and 0 when on
#define inp 10
#define out 11
#define led 13
void setup() {
  // put your setup code here, to run once:
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(11,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(inp))
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);
}
