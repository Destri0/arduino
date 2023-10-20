/*
--Code develop by Fran
*/
const int led1 = 9; // Declaramos el pin 9 del led como "led1"
const int pote = 0; // Declaramos el pin A0 del potenciometro como "pote"
int intensidad; // Declaramos una variable para la intensidad del brillo

void setup() { 
  pinMode(led1, OUTPUT); //Indicamos que el pin del "led1" se comporte como una salida   
} 
  
void loop() { 
  /*
  Decimos que la intensidad es igual a el valor del potenciometro dividido por 4 ya 
  que los valores del potenciometro van desde 0 al 1023 y el led desde el 0 al 255
  */
  intensidad = analogRead(pote) / 4;
  analogWrite(led1, intensidad); //Le decimos al pin del "led1" la intensidad recogida en el parametro anterior
}