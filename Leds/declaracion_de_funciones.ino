const int led1 = 9;
const int led2 = 10;
const int led3 = 11;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void sec1(){
  digitalWrite(led3, LOW);
  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(100);
}

void loop() {
 sec1();
}
