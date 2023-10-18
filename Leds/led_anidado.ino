/*
--Code develop by Destri
*/
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  for (int pin=9; pin<=11 ;pin++){
  for (int brillo=0; brillo<=255; brillo++){
    analogWrite(pin, brillo);
    delay(25);
  }
  }
}
