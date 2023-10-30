const int pul = 7;  
const int led1 = 9;   

int estado = 0;     
int uestado = 0;  
int brillo = LOW; 

void setup() {
  pinMode(pul, INPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  estado = digitalRead(pul);
  if (estado != uestado) {
    if (estado == HIGH) {
      while (digitalRead(pul) == HIGH) {
      }
      brillo = (brillo == LOW) ? HIGH : LOW;
      digitalWrite(led1, brillo);
    }
    delay(50); 
  }
}
