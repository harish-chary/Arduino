#define activate 8
void setup() {
  Serial.begin(9600);
  pinMode(activate,OUTPUT);
}

void loop() {
  if(Serial.available()>0)
  {
    String inp = Serial.readStringUntil(';');
    if(inp=="on")
      digitalWrite(activate,HIGH);
    else if(inp=="off")
      digitalWrite(activate,LOW);
    Serial.println(inp);
  }
  delay(25);
}
