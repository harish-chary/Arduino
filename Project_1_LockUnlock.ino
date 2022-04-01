char state = 'L';
#define button 10
#define inp 11
#define led 13
void setup() {
  // put your setup code here, to run once:
  digitalWrite(button,HIGH);
  pinMode(inp,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(!digitalRead(button));
  if(!digitalRead(button))
    {digitalWrite(led,HIGH);}
  else
    digitalWrite(led,LOW);
}
