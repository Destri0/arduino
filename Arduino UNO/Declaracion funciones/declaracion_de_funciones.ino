/*
--Code develop by Fran
*/
// Declaramos todos los pines de los leds. Llamando a cada pin por un nombre
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;

void setup() {
  //Indicamos que los pines se comporten como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void sec1(){
  digitalWrite(led3, LOW); //Mediante una señal digital le decimos que se apague el led con "LOW"
  digitalWrite(led1, HIGH);  //Mediante una señal digital le decimos que se encienda al maximo con "HIGH"
  delay(100); //Esperamos
  digitalWrite(led1, LOW); //Mediante una señal digital le decimos que se apague el led con "LOW"
  digitalWrite(led2, HIGH);  //Mediante una señal digital le decimos que se encienda al maximo con "HIGH"
  delay(100); //Esperamos
  digitalWrite(led2, LOW); //Mediante una señal digital le decimos que se apague el led con "LOW"
  digitalWrite(led3, HIGH);  //Mediante una señal digital le decimos que se encienda al maximo con "HIGH"
  delay(100); //Esperamos
}

void loop() {
 sec1(); //Llamamos a la función anteriormente declarada para que se produzca lo que contiene la función
}
