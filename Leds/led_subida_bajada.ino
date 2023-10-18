/*
--Code develop by Destri
*/
// Declaramos todos los pines de los leds. Llamando a cada pin por un nombre
const int led1 = 9;
const int led2 = 10;

void setup() {
    //Indicamos con un bucle for que pines queremos que se comporten como salidas
    for(int l=9; l<11; l++) pinMode(l, OUTPUT);
}

void loop() {
    for (int i=0; i<=255; i++){ //Creamos el primer bucle for en el que se indica desde que intensidad inicia el led a subir hasta el máximo que es "255". De uno en uno
      analogWrite(led1, i); //Decimos que el primer led incremente la intensidad
      analogWrite(led2, 255 - i); //Decimos que el segundo led disminuya la intensidad gracias a indicarle que realice "255 - i" el incremento.
      delay(10); //Esperamos
    }
    for (int i=0; i<=255; i++){ //Creamos el segundo bucle for igual que el primero
      analogWrite(led2, i); //Decimos que el segundo led incremente la intensidad
      analogWrite(led1, 255 - i); //Decimos que el primer led disminuya la intensidad gracias a indicarle que realice "255 - i" el incremento.
      delay(10);
    }
}
