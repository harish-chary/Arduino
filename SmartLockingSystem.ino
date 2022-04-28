#include <Keypad.h>
#include <Servo.h>
char hexKeys[4][4]={{'1','2','3','A',},{'4','5','6','B',},{'7','8','9','C',},{'*','0','#','D',}};
byte rowPins[4]={9,8,7,6};
byte colPins[4]={5,4,3,2};
Keypad key = Keypad(makeKeymap(hexKeys),rowPins,colPins,4,4);
Servo s;
#define servoPin 13
#define start 10
#define startout 11
#define buzz 12
#define lock 1
#define unlock 120
unsigned long t;
char state='L';
char input;
String correct = "1234";
String masterkey = "A#B#";
String password = "";
int i=0;
int j=0;
void setup() {
  pinMode(servoPin,OUTPUT);
  pinMode(startout,OUTPUT);
  digitalWrite(startout,HIGH);
  pinMode(buzz,OUTPUT);
  pinMode(start,INPUT);
  Serial.begin(9600);
  s.attach(servoPin);
  s.write(lock);
}


void masterKey()
{
 correct="";
      Serial.print("Enter new password: ");
      while(j<4)
      {
      input = key.getKey();
      if(input)
      {
        Serial.print(input);
        correct+= input;
        j++;
      }
    }
    Serial.println("\nNew Password: "+correct); 
}


void inp()
{
  
  Serial.println("Go");
    while(i<4 && millis()-t<5000LU)
    {
      input = key.getKey();
      if(input)
      {
        Serial.print(input);
        password+= input;
        i++;
      }
   }
}


void right()
{
  Serial.print("Unlocked -- ");
      s.write(unlock);
      digitalWrite(buzz,HIGH);
      delay(2000);
      Serial.println("Locked");
      s.write(lock);
      digitalWrite(buzz,LOW);
}


void wrong()
{
  Serial.println("Incorrect Password!");
      for (int j = 0; j < 3; j++)
      {
        digitalWrite(buzz, HIGH);
        delay(120);
        digitalWrite(buzz, LOW);
        delay(120);
      }
}

void reinitialize()
{
  password="";
    i=0;
    j=0;
    delay(1000);
    digitalWrite(buzz, HIGH);
    delay(50);
    digitalWrite(buzz, LOW);
}


void loop() {
  if(!digitalRead(start))
  {
    t = millis();
    inp();
    Serial.println();
    if(password=="")
    {
      Serial.println("Time out");
      for (int j = 0; j < 3; j++)
      {
        digitalWrite(buzz, HIGH);
        delay(120);
        digitalWrite(buzz, LOW);
        delay(120);
      }
    }
    else if(masterkey==password)
    {
      masterKey();
    }
    else if(correct==password)
    {
      right();
    }
    else
      {
        wrong();
      }
    reinitialize();
  }
  delay(2);
}
