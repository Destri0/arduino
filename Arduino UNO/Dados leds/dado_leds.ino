/*
--Codigo realizado por Fran
*/
/* 
  Declaramos todos los pines como una palabra para que sea 
  mas facil la referencia en las funciones, etc...
*/
const int ledui = 8;
const int leduc = 7;
const int ledud = 6;
const int ledc = 5;
const int ledbi = 2;
const int ledbc = 3;
const int ledbd = 4;
const int pul = 9;

void setup () {
/*
  Indicamos que desde el pin 2 hasta el pin 8 se comporten
  como una salida ademas le decimos que se apaguen todos.
*/
for(int pin=2; pin<=8; pin++){
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}
  pinMode (pul, INPUT); // Indicamos al pin del "pul" que se comporte como una entrada 
}

void dado (unsigned char num) {
  switch (num) {
            
    case 1: //Declaramos el primer caso (1 en el dado)
            digitalWrite (ledui, LOW);
            digitalWrite (leduc, LOW);
            digitalWrite (ledud, LOW);
            digitalWrite (ledc, HIGH);
            digitalWrite (ledbi, LOW);
            digitalWrite (ledbc, LOW);
            digitalWrite (ledbd, LOW);           
            break;
            
    case 2: //Declaramos el segundo caso (2 en el dado)
            digitalWrite (ledui, LOW);
            digitalWrite (leduc, HIGH);
            digitalWrite (ledud, LOW);
            digitalWrite (ledc, LOW);
            digitalWrite (ledbi, LOW);
            digitalWrite (ledbc, HIGH);
            digitalWrite (ledbd, LOW);              
            break;
            
    case 3: //Declaramos el tercer caso (3 en el dado)
            digitalWrite (ledui, HIGH);
            digitalWrite (leduc, LOW);
            digitalWrite (ledud, LOW);
            digitalWrite (ledc, HIGH);
            digitalWrite (ledbi, LOW);
            digitalWrite (ledbc, LOW);
            digitalWrite (ledbd, HIGH);   
            break;
            
    case 4: //Declaramos el cuarto caso (4 en el dado)
            digitalWrite (ledui, HIGH);
            digitalWrite (leduc, LOW);
            digitalWrite (ledud, HIGH);
            digitalWrite (ledc, LOW);
            digitalWrite (ledbi, HIGH);
            digitalWrite (ledbc, LOW);
            digitalWrite (ledbd, HIGH);   
            break;
            
    case 5: //Declaramos el quinto caso (5 en el dado)
            digitalWrite (ledui, HIGH);
            digitalWrite (leduc, LOW);
            digitalWrite (ledud, HIGH);
            digitalWrite (ledc, HIGH);
            digitalWrite (ledbi, HIGH);
            digitalWrite (ledbc, LOW);
            digitalWrite (ledbd, HIGH);   
            break;
            
    case 6: //Declaramos el sexto caso (6 en el dado)
            digitalWrite (ledui, HIGH);
            digitalWrite (leduc, HIGH);
            digitalWrite (ledud, HIGH);
            digitalWrite (ledc, LOW);
            digitalWrite (ledbi, HIGH);
            digitalWrite (ledbc, HIGH);
            digitalWrite (ledbd, HIGH);
            break;
        
    default:
    case 0: //Declaramos el caso base que es el 0 (Todo apagado)
            digitalWrite (ledui, LOW);
            digitalWrite (leduc, LOW);
            digitalWrite (ledud, LOW);
            digitalWrite (ledc, LOW);
            digitalWrite (ledbi, LOW);
            digitalWrite (ledbc, LOW);
            digitalWrite (ledbd, LOW);
            break;       
  }
}


void loop () {
  unsigned int numero;
  while (!digitalRead (9));//Esperamos a que se apriete el pulsador
  dado(0);//Dejamos apagados los leds mientra
  while (digitalRead (9));//Esperamos a que se suelte el pulsador
  numero = random(1, 7);//Generamos un numero al azar entre 1 y 6
  dado(numero);//Despues mostramos el caso que salga del numero anterior
}