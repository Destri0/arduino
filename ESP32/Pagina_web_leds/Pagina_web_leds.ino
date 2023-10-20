/*
--Code develop by Fran
*/
//Llamamos a las librerias necesarias para crear el servidor y poner wifi
#include <WiFi.h>
#include <WebServer.h>
const char* ssid = "";  // Indicamos el "SSID" de tu internet
const char* password = "";  //Indicamos la clave de tu internet
/*
  Declaramos un objeto para poder acceder a la pagina web indicandole
  que utilizaremos el puerto 80 el estandar para las WEB HTTP
*/
WebServer server(80);
/*
   Declaramos el estado inicial de los LEDs
*/
int LED1pin = 4;
bool LED1Estado = LOW;
int LED2pin = 5;
bool LED2Estado = LOW;

void setup() {
  //Indicamos los baudios a los que utilizaremos la conexión entre el ESP32 y la consola de arduino
  Serial.begin(115200);
  //Indicamos que ambos pines se comporten como salidas
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
/*
  Configuramos la conexión wifi
 */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Esperamos a la conexión
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado a ");
  Serial.println(ssid);
  Serial.print("Direccion IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", primconect); // Procesamos la información de la conexión
  server.on("/led1on", led1on); // Procesamos el estado de encendido del led1
  server.on("/led1off", led1off); // Procesamos el estado de apagado del led1
  server.on("/led2on", led2on); // Procesamos el estado de encendido del led2
  server.on("/led2off", led2off); // Procesamos el estado de apagado del led2
  server.onNotFound(nofunciona); // Gestionamos los errores de la pagina web si no nos encontramos en ninguna de las anteriores declaradas

  server.begin();
  Serial.println("Servidor HTTP iniciado");

}
void loop() {
  server.handleClient(); // Llamamos al metodo "handleClient" para gestionar las peticiones HTTP. Recibir las peticiones y lanzar las funciones
  if (LED1Estado) // Recibimos la peticion del estado del led1 y dependiendo del caso le indicamos el primer caso o el segundo
  {
    digitalWrite(LED1pin, HIGH); // Le decimos al LED1 que se encienda en el primer caso
  }
  else
  {
    digitalWrite(LED1pin, LOW); // Le decimos al LED1 que se apague en el segundo caso
  }

  if (LED2Estado) // Recibimos la peticion del estado del led2 y dependiendo del caso le indicamos el primer caso o el segundo
  {
    digitalWrite(LED2pin, HIGH); // Le decimos al LED2 que se encienda en el primer caso
  }
  else
  {
    digitalWrite(LED2pin, LOW);  // Le decimos al LED2 que se apague en el segundo caso
  }
}

void primconect() {
  LED1Estado = LOW; // Cambiamos de estado las variables de los LED's
  LED2Estado = LOW;
  Serial.println("PIN4 Estado: OFF | PIN5 Estado: OFF"); // Mostramos por el monitor de Arduino la información del estado de los LEDS
  server.send(200, "text/html", SendHTML(LED1Estado, LED2Estado)); // Actualizamos la página
}

void led1on() {
  LED1Estado = HIGH; // Cambiamos de estado la variable del LED
  Serial.println("PIN4 Estado: ON"); // Mostramos por el monitor de Arduino que el estado del led1 es encendido
  server.send(200, "text/html", SendHTML(true, LED2Estado)); //Enviamos a la pagina web el cambio de estado del led1
}

void led1off() {
  LED1Estado = LOW; // Cambiamos de estado la variable del LED
  Serial.println("PIN4 Estado: OFF");  // Mostramos por el monitor de Arduino que el estado del led1 es apagado
  server.send(200, "text/html", SendHTML(false, LED2Estado));  //Enviamos a la pagina web el cambio de estado del led1
}

void led2on() {
  LED2Estado = HIGH; // Cambiamos de estado la variable del LED
  Serial.println("PIN5 Estado: ON");  // Mostramos por el monitor de Arduino que el estado del led2 es encendido
  server.send(200, "text/html", SendHTML(LED1Estado, true)); //Enviamos a la pagina web el cambio de estado del led2
}

void led2off() {
  LED2Estado = LOW; // Cambiamos de estado la variable del LED
  Serial.println("PIN5 Estado: OFF"); // Mostramos por el monitor de Arduino que el estado del led2 es apagado
  server.send(200, "text/html", SendHTML(LED1Estado, false)); //Enviamos a la pagina web el cambio de estado del led2
}

void nofunciona() {
  server.send(404, "text/plain", "La pagina no existe"); // Enviamos un error de que la pagina no existe en el caso de que no sea ninguna de las anteriores
}

/*
   Definimos todo el HTML y el CSS del servidor WEB
*/
String SendHTML(int led1estado, int led2estado) {

  String ptr = "<!DOCTYPE html> <html>\n"; // Etiquetas de cabecera de html
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n"; // Metas de escalado para que se vea bien la pagina web en cualquier dispositivo
  ptr += "<title>Control LED</title>\n"; // Indicamos el titulo de la pagina web
  
/*
  En la siguientes líneas de código definimos el CSS de la página web indicando los colores de botones, alineación de letras y botones, etc
 */
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;margin-top: 50px;} h4 {color: #444444;margin-bottom: 10px;margin-top: 25px;}\n";
  ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 10px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #1ddb1d;}\n";
  ptr += ".button-on:active {background-color: #1ddb1d;}\n";
  ptr += ".button-off {background-color: #db1d1d;}\n";
  ptr += ".button-off:active {background-color: #800f0f;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-top: 2px;margin-bottom: 10px;}\n";
  ptr += "v {color: #1ddb1d;}\n";
  ptr += "r {color: #db1d1d;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";

  ptr += "<h1>Servidor WEB</h1>\n"; // Encabezado de la pagina web
  ptr += "<h4>LED 1</h4>\n";
/*
  En las siguientes líneas dependiendo de los parámetros del estado de los leds cambiará la información en la página web
 */
  if (led1estado) 
  {
    ptr += "<a class=\"button button-off\" href=\"/led1off\">OFF</a><p>Estado: <v>ON</v></p>\n";
  }
  else
  {
    ptr += "<a class=\"button button-on\" href=\"/led1on\">ON</a><p>Estado: <r>OFF</r></p>\n";
  }
  ptr += "<h4>LED 2</h4>\n";
  if (led2estado)
  {
    ptr += "<a class=\"button button-off\" href=\"/led2off\">OFF</a><p>Estado: <v>ON</v></p>\n";
  }
  else
  {
    ptr += "<a class=\"button button-on\" href=\"/led2on\">ON</a><p>Estado: <r>OFF</r></p>\n";
  }
  ptr += "<h3>Develop by Fran</h3>\n";
  ptr += "</body>\n"; // Cerramos la etiqueta del cuerpo
  ptr += "</html>\n"; // Cerramos la etiqueta de html
  return ptr;
}