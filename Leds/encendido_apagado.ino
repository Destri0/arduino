/*
--Code develop by Fran
*/
const int led1 = 8;  // Declaramos el pin del led. LLamando a ese pin por un nombre

void setup() {
  pinMode(led1, OUTPUT); //Indicamos que el pin "led1(8)" se comporte como una salida
}

void loop() {
  digitalWrite(led1, HIGH); //Mediante una señal digital le decimos que se encienda al maximo con "HIGH"
  delay(100); //Esperamos
  digitalWrite(led1, LOW); //Mediante una señal digital le decimos que se apague el led con "LOW"
  delay(100); //Esperamos para volver a repetir todo
}
