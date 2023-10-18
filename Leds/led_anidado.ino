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

void loop() {
  for (int pin=9; pin<=11 ;pin++){ //Creamos el primer bucle for indicando desde el pin de inicio del bucle hasta qué pin tiene que llegar
  for (int brillo=0; brillo<=255; brillo++){ //Creamos el segundo bucle for indicando desde el comienzo del brillo hasta el final. Como es una señal analógica empezara por el 0 y terminara en 255
    analogWrite(pin, brillo); //Indicamos que queremos la variable pin para el led y la variable brillo para el valor de encendido del led
    delay(25); //Tiempo de espera para repetir acción
  }
  }
}
