int switchState = 0;
int i = 0;
int del = 250;
    
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }

  else {

    for (i=0; i<=10; i++) {
    
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);

      delay(del);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      delay(del);

      del = del-30;
      if (del < 30) {
        del = 30;
      }

      switchState = digitalRead(2);
      if (switchState == LOW) {
        del = 250;
        break;
      }
    }
  }
}
