const int pul = 7;  
const int led1 = 9;   

int estado = 0;     
int uestado = 0;  
boolean brillo = false;


void setup() {
  pinMode(pul, INPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  estado = digitalRead(pul);
  if (estado != uestado) {
    if (estado == HIGH) {
      while (digitalRead(pul) == HIGH) {
        delay(100);
      }
      brillo = !brillo;
      digitalWrite(led1, brillo);
    }
    delay(50); 
  }
}
