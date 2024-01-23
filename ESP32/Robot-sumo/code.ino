#include <WiFi.h>
#include <WebServer.h>

const char* wifid = "HUAWEI-WSh9";
const char* contra = "BARCCavS";
WebServer server(80);
bool restado = LOW;
bool restado2 = LOW;

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(wifid, contra);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado a ");
  Serial.println(wifid);
  Serial.print("Direccion IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/control", primconect);  
  server.on("/ron", ron);
  server.on("/roff", roff);
  server.on("/consola", consolaPage); 
  server.onNotFound(nofunciona);

  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();
  if (restado2) {
    digitalWrite(1, HIGH);
  } else {
    digitalWrite(1, LOW);
  }
}

void handleRoot() {
  restado = LOW;
  restado2 = LOW; 
  Serial.println("Robot Estado: OFF"); 
  server.send(200, "text/html", SendHTML(restado, restado2));
}

void primconect() {
  restado = LOW;
  restado2 = LOW; 
  Serial.println("Robot Estado: OFF"); 
  server.send(200, "text/html", SendHTML(restado, restado2));
}

void consolaPage() {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>Consola</title>\n";
  ptr += "<link rel=\"shortcut icon\" href=\"https://t1.ea.ltmcdn.com/es/posts/5/8/1/cuidados_de_una_capibara_20185_600.jpg\">\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px; padding-top: 80px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;margin-top: 50px;} h4 {color: #444444;margin-bottom: 10px;margin-top: 25px;}\n";
  ptr += ".header {background-color: #007bff; padding: 20px; position: fixed; top: 0; left: 0; right: 0;}\n";  
  ptr += ".header-content h1 {color:#fff; font-size:36px; margin:0 auto; width: 50%;}\n";  
  ptr += ".header-content img {border-radius: 50%; height: 80px;width: 80px;float: left;margin-right: 20px;}\n";
  ptr += ".consola-button {background-color: white; color: blue; padding: 5px 10px; text-decoration: none; position: absolute; top: 0; right: 0; z-index: 1;}\n";
  ptr += "footer {background-color: #007bff; padding: 20px;text-align: center;position: fixed;bottom: 0;width: 100%; left: 0; right: 0;}\n";
  ptr += ".footer-content {margin: 0 auto; max-width: 800px;}\n";
  ptr += ".footer-content p {margin: 0; padding: 10px; font-size: 16px; color: #333;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<header class=\"header\">\n";
  ptr += "<div class=\"header header-content\">\n";
  ptr += "<img src=\"https://t1.ea.ltmcdn.com/es/posts/5/8/1/cuidados_de_una_capibara_20185_600.jpg\" alt=\"Capibara\">\n";
  ptr += "<a href=\"/control\" class=\"consola-button\">Control</a>\n";
  ptr += "<h1>Capibara WEB</h1>\n";
  ptr += "</div>\n";
  ptr += "</header>\n";
  ptr += "<h1>Consola</h1>\n";
  ptr += "<footer>\n";
  ptr += "<div class=\"footer-content\">\n";
  ptr += "<p>Develop by Capibara Team</p>\n";
  ptr += "</div>\n";
  ptr += "</footer>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  server.send(200, "text/html", ptr);
}

void ron() {
  restado2 = HIGH;
  Serial.println("Robot Estado: ON");
  server.send(200, "text/html", SendHTML(true, restado));
}

void roff() {
  restado2 = LOW;
  Serial.println("Robot Estado: OFF");
  server.send(200, "text/html", SendHTML(false, restado));
}

String SendHTML(int restado, int restado2) {
String ptr = "<!DOCTYPE html> <html>\n"; 
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n"; 
  ptr += "<title>Control Robot</title>\n"; 
  ptr += "<link rel=\"shortcut icon\" href=\"https://t1.ea.ltmcdn.com/es/posts/5/8/1/cuidados_de_una_capibara_20185_600.jpg\">\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px; padding-top: 80px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;margin-top: 50px;} h4 {color: #444444;margin-bottom: 10px;margin-top: 25px;}\n";
  ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 10px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #1ddb1d;}\n";
  ptr += ".button-on:active {background-color: #1ddb1d;}\n";
  ptr += ".button-off {background-color: #db1d1d;}\n";
  ptr += ".button-off:active {background-color: #800f0f;}\n";
  ptr += "footer {background-color: #007bff; padding: 20px;text-align: center;position: fixed;bottom: 0;width: 100%; left: 0; right: 0;}\n";
  ptr += ".footer-content {margin: 0 auto; max-width: 800px;}\n";
  ptr += ".footer-content p {margin: 0; padding: 10px; font-size: 16px; color: #333;}\n";
  ptr += ".header {background-color: #007bff; padding: 20px; position: fixed; top: 0; left: 0; right: 0;}\n";  
  ptr += ".header-content h1 {color:#fff; font-size:36px; margin:0 auto; width: 50%;}\n";  
  ptr += ".header-content img {border-radius: 50%; height: 80px;width: 80px;float: left;margin-right: 20px;}\n";
  ptr += ".consola-button {background-color: white; color: blue; padding: 5px 10px; text-decoration: none; position: absolute; top: 0; right: 0; z-index: 1;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-top: 2px;margin-bottom: 10px;}\n";
  ptr += "v {color: #1ddb1d;}\n";
  ptr += "r {color: #db1d1d;}\n";
  ptr += "</style>\n";
  ptr += "<header class=\"header\">\n";
  ptr += "<div class=\"header header-content\">\n";
  ptr += "<img src=\"https://t1.ea.ltmcdn.com/es/posts/5/8/1/cuidados_de_una_capibara_20185_600.jpg\" alt=\"Capibara\">\n";
  ptr += "<a href=\"/consola\" class=\"consola-button\">Consola</a>\n";
  ptr += "<h1>Capibara WEB</h1>\n";
  ptr += "</div>\n";
  ptr += "</header>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h4>Funcionamiento</h4>\n";
  if (restado) 
  {
    ptr += "<a class=\"button button-off\" href=\"/roff\">OFF</a><p>Estado: <v>ON</v></p>\n";
  }
  else
  {
    ptr += "<a class=\"button button-on\" href=\"/ron\">ON</a><p>Estado: <r>OFF</r></p>\n";
  }
  ptr += "<footer>\n";
  ptr += "<div class=\"footer-content\">\n";
  ptr += "<p>Develop by Capibara Team</p>\n";
  ptr += "</div>\n";
  ptr += "</footer>\n";
  ptr += "</body>\n";
  ptr += "</html>\n"; 
  return ptr;
}

void nofunciona() {
  server.send(404, "text/plain", "La pagina no existe");
}