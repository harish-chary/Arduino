//step 2: program to make processor wait for the input, and wait for 10 sec before closing again
#define start 2
#define correct 3
#define wrong 4
#define output1 5
#define output2 6
#define output3 7
#define buzzer 8
#define led 13
char state = 'L';
int flag = 0;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(start, INPUT);
  pinMode(correct, INPUT);
  pinMode(wrong, INPUT);
  digitalWrite(output1, HIGH); //taking output from one single port was not working
  digitalWrite(output2, HIGH);
  digitalWrite(output3, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (!digitalRead(start)) //after pressing start button
  {
    digitalWrite(led,HIGH);
    do
    {
      while (!digitalRead(correct) || !digitalRead(wrong)) {
        flag = 1; //waiting for input
      }
      delay(1); //wasn't working without the delay
      if (!digitalRead(wrong))
      {
        state = 'L';
      }
      else if (!digitalRead(correct))
      {
        state = 'U';
      }
    } while (flag == 0);
    if (state == 'U')
    { Serial.print("Unlocked!");
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      Serial.println(" -- Locked!");
    }
    else
    {
      Serial.println("Wrong Password!");
      for (int i = 0; i < 3; i++)
      {
        digitalWrite(buzzer, HIGH);
        delay(120);
        digitalWrite(buzzer, LOW);
        delay(120);
      }
    }
    flag = 0; //reseting values
    state = 'L';
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
  }
  digitalWrite(led,LOW);
  delay(2);
}
