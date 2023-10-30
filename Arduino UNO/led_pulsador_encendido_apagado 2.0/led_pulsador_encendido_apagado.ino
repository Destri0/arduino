const int pul = 7;  
const int led1 = 9;   

int estado = 0;     
boolean brillo = false;


void setup() {
  pinMode(pul, INPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  estado = digitalRead(pul);
    if (estado == HIGH) {
      while (digitalRead(pul) == HIGH) {
        delay(5);
      }
      brillo = !brillo;
      digitalWrite(led1, brillo);
    }
    delay(50); 
}
