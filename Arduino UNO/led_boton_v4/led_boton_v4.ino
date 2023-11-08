/*
--Code develop by Fran
*/
const int pul = 7; // Declaramos el pin 9 del led como "led1"
const int led1 = 9; // Declaramos el pin 7 del pulsador como "pul"  
boolean brillo = false; /* Declaramos una variable boolean para el brillo del led dejando 
a esa variable boolean como el estado de false = apagado */

void setup() {
  pinMode(pul, INPUT); //Indicamos que el pin del "led1" se comporte como una salida   
  pinMode(led1, OUTPUT); //Indicamos que el pin del "pul" se comporte como una entrada
}

void loop() {
/* 
 - En el siguiente codigo vamos a hacer que si el led se encuentra apagado y pulsa 
 - o dejas precionado el pulsador se encienda el led y si lo sueltas se quede encendido
 - y en el caso de que el led se encuentre encendio si lo pulsa o lo dejas precionado 
 - el led se apaga y se queda apagado.
*/
  if (digitalRead(pul) == HIGH) { // Leemos los datos del pulsador y indicamos que si se encuentra ("HIGH" = precionado)
    /*Si "brillo" es false, el LED se apaga y el brillo se establece en false*/
    if (brillo == true) { 
      brillo = false;
      digitalWrite(led1, LOW);
    } else if (brillo == false) {
    /*Si "brillo" es true, el LED se enciende y el brillo se establece en true*/
      brillo = true; 
      digitalWrite(led1, HIGH);
    }
    /*Utilizamos "while" para esperar a que se suelte el pulsador antes de continuar. Asi evitamos que el estado del led
    cambie rápdidamente mientras se mantiene presionado el pulsador*/
    while (digitalRead(pul) == HIGH) { 
      delay(5);
    }
  }

  delay(50); // Agregamos el delay para evitar problemas al ejecutarse demasiado rapido
}
