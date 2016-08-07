int lampe = PB4;
int speaker = PB1;
int schalter = PB2;

bool flag = true;

void setup() {
  pinMode(speaker, OUTPUT);
  pinMode(lampe, OUTPUT);
  pinMode(schalter, INPUT_PULLUP);

  digitalWrite(speaker, LOW);
  digitalWrite(lampe, LOW);
}

void loop() {
  if (digitalRead(schalter) == LOW) {
    digitalWrite(lampe, HIGH);
    if (flag == true) {
      flag = false;
      playTune();
    }
  }
  if (digitalRead(schalter) == HIGH) {
    flag = true;
    digitalWrite(speaker, LOW);
    digitalWrite(lampe, LOW);
    //delay(300);
  }
}

void playTune(void)
{
  for (int i = 0; i < 7; i++) {
    digitalWrite(speaker, HIGH);
    delay(50);
    digitalWrite(speaker, LOW);
    delay(50);
  }
}
