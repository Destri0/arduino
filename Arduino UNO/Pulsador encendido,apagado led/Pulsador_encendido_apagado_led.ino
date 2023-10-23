/*
--Code develop by Fran
*/
const int led1 = 9; // Declaramos el pin 9 del led como "led1"
const int pul = 7; // Declaramos el pin 7 del pulsador como "pul"
int estado = 0; // Declaramos una variable "estado" que sera 0

void setup() { 
    pinMode(led1, OUTPUT); //Indicamos que el pin del "led1" se comporte como una salida   
    pinMode(pul, INPUT); //Indicamos que el pin del "pul" se comporte como una entrada   
} 

void loop() { 
  if(digitalRead(pul) && estado==0){ //En este if indicamos que si el pulsador se encuentra presionado y el estado es 0 ecendemos el led 
    digitalWrite(led1, HIGH); //Encendemos el led         
    delay(100); //Esperamos
    estado=1; //Guardamos el estado en este caso en 1 que seria encendido el led                     
  } 
  if(digitalRead(pul) && estado==1){  //En este segundo if indicamos que si el pulsador se presiona de nuevo y el estado es 1 apagamos el led
    digitalWrite(led1, LOW); //Apagamos el led   
    delay(100); //Esperamos
    estado=0;//Guardamos el estado del led como 0 (Led apagado)         
  }
}