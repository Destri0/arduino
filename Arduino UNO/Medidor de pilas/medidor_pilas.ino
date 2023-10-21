/*
--Codigo realizado por Fran
*/
/* 
  Declaramos todos los pines como una palabra para que sea 
  mas facil la referencia en las funciones, etc...
*/
const int ledr = 8;
const int leda = 9;
const int ledv = 10;
const int pila = 0;
// Declaramos las siguientes variables que vamos a utilizar
int analogvalor = 0;
float voltaje = 0;
// Declaramos los umbrales de voltajes con los que vamos a saber si la pila tiene una carga alta, media o baja
float maximo = 1.3;
float medio = 0.8;
float minimo = 0.01;

void setup() {
  Serial.begin(9600); // Realizamos conexión con la consola
  //Le decimos a los pines de los leds que se comporten como salidas y al pin de la pila que se comporte como una entrada
  pinMode(ledr, OUTPUT);
  pinMode(leda, OUTPUT);
  pinMode(ledv, OUTPUT);
  pinMode(pila, INPUT);
}

void loop() {
  analogvalor = analogRead(pila); // Decimos que la variable "analogvalor" es igual al valor leida de la pila
  voltaje = 0.0048 * analogvalor; // Decimos que "voltaje" es igual al anterior valor multiplicado por "0.0048"
  // Indicamos que si el valor es mayor o igual que 1.3 se encienda el led verde y nos diga el voltaje exacto por la consola
  if (voltaje >= maximo){
    digitalWrite(ledv, HIGH);
    Serial.print("Volataje alto:");
    Serial.println(voltaje);
    delay(800);
    digitalWrite(ledv, LOW);
  }
  /*
    En el siguiente caso indicamos que si el voltaje es menor a 1.3 y mayor a 0.8 
    se encienda el led amarillo y nos devuelva por la consola el voltaje exacto
  */
  else if (voltaje < maximo && voltaje > medio){
    digitalWrite(leda, HIGH);
    Serial.print("Volataje medio:");
    Serial.println(voltaje);
    delay(800);
    digitalWrite(leda, LOW);
  }
  /*
    En el ultimo caso le indicamos que si el voltaje es mayor que 0.01 se encienda
    el led rojo y que indique su voltaje exacto
  */
  else if (voltaje > minimo){
    digitalWrite(ledr, HIGH);
    Serial.print("Volataje bajo:");
    Serial.println(voltaje);
    delay(800);
    digitalWrite(ledr, LOW);
  }
  //Si no se da ninguno de los anteriores caso indicamos que todos los leds esten apagados
  digitalWrite(ledv, LOW);
  digitalWrite(leda, LOW);
  digitalWrite(ledr, LOW);
}
