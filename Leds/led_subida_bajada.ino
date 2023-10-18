/*
--Code develop by Destri
*/
const int led1 = 9;
const int led2 = 10;

void setup() {
    for(int l=9; l<11; l++) pinMode(l, OUTPUT);
}

void loop() {
    for (int i=0; i<=255; i++){
      analogWrite(led1, i);
      analogWrite(led2, 255 - i);
      delay(10);
    }
    for (int i=0; i<=255; i++){
      analogWrite(led2, i);
      analogWrite(led1, 255 - i);
      delay(10);
    }
}
