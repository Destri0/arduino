/*
--Codigo realizado por Fran
*/
#include <Servo.h> //Incluimos la liberia del servomotor en nuestro código
/*
  Declaramos los pines de el servomotor y el potenciometro como una palabra
  para hacer las referencias mas rapido en el codigo. Ademas declaramos dos
  variables que usaremos proximamente que son el angulo del servomotor y el
  potenciometro.
*/
const int servo = 9; 
const int pote = 5;
int angulo; 
int potenciometro;

Servo myServo; // Creamos el objeto myServo                   

void setup(){
   myServo.attach(servo); //Indicamos a nuestro objeto "myServo" el pin anteriormente declarado
   pinMode(pote, INPUT);  //Indicamos a pin del "pote" que se comporte como una entrada
}

void loop(){
   potenciometro=analogRead(pote); //Decimos que la variable "potenciometro" es igual a la información leida por el potenciometro.
   /*
    Decimos que el "angulo" es igual al mapeo de la informacion recibida por 
    el potenciometro que va de 0 a 1023 y la traducimos al angulo que tiene 
    el servomotor que va desde el 0 al 179.
   */
   angulo=map(potenciometro, 0, 1023, 0, 179);
   myServo.write(angulo); //Le mandamos al servomotor el angualo indicado anteriormente
   delay(15); //Esperamos
}