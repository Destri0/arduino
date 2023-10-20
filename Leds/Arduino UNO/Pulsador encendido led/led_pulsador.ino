/*
--Code develop by Fran
*/
const int led1 = 9; // Declaramos el pin 9 del led como "led1"
const int pul = 7; // Declaramos el pin 7 del pulsador como "pul"
int estado; // Declaramos una variable para el estado del pulsador
void setup() { 
  pinMode(led1, OUTPUT);//Indicamos que el pin del "led1" se comporte como una salida   
  pinMode(pul, INPUT);//Indicamos que el pin del "pul" se comporte como una entrada
} 
  
void loop() { 
  estado=digitalRead(pul); //Decimos que la variable estado es igual a la información leida de "pul"
if  (estado==1){ //Decimos que si el estado del pulsador se encuentra en activo se realice la siguiente función
  digitalWrite(led1, HIGH);//Indicamos que el "led1" se encienda
  }
if (estado==0){ //Decimos que el caso contrario de que no se encuentre el pulsador presionado que realice la siguiente función
  digitalWrite(led1,LOW); //Indicamos que el "led1" se apague
  }
}