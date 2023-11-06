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
      if (brillo) {
        brillo = false;
        digitalWrite(led1, LOW);

      } else {
        brillo = true;
        digitalWrite(led1, HIGH);
      }
    }
    delay(50); 
}
