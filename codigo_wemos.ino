WEMOS

#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>

const char* ssid = "RUBENS 2";
const char* password = "Val2321eraB1111";

AsyncWebServer server(80);
WebSocketsServer webSocket(81);

int velocidad = 0; 
int velocidadMax = 255;
int velocidadMin = 150;
bool enMovimiento = false;
bool retrocediendo = false;

int m1_sta1 = D1;
int m1_sta2 = D2;

int m2_pwm = D5;
int m2_sta1 = D7;
int m2_sta2 = D6;

int luzPin = D3;

void setup() {
Serial.begin(115200);
Serial.println("Iniciando programa...");

pinMode(m1_sta1, OUTPUT);
pinMode(m1_sta2, OUTPUT);
pinMode(m2_pwm, OUTPUT);
pinMode(m2_sta1, OUTPUT);
pinMode(m2_sta2, OUTPUT);
pinMode(luzPin, OUTPUT);

apagarLuces();
detenerDireccion();
detenerArranque();

WiFi.begin(ssid, password);
Serial.print("Conectando a WiFi...");
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("\nConectado a WiFi");
Serial.println(WiFi.localIP());

webSocket.begin();
webSocket.onEvent(onWebSocketEvent);

server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
request->send(200, "text/plain", "Servidor WebSocket para carrito");
});
server.begin();
}

void loop() {
webSocket.loop();
}

void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
    if (type == WStype_TEXT) {
    String command = String((char *)payload);
    Serial.println("Comando recibido: " + command);
    if (command == "luces_on") encenderLuces();
    else if (command == "luces_off") apagarLuces();
    else if (command == "left") izquierda();
    else if (command == "right") derecha();
    else if (command == "stop_dir") detenerDireccion();
    else if (command == "accelerate") acelerar();
    else if (command == "decelerate") desacelerar();
    else if (command == "stop_motor") detenerArranque();

}
}

void izquierda() {
Serial.println("Girando a la izquierda");
digitalWrite(m1_sta1, HIGH);
digitalWrite(m1_sta2, LOW);
}

void derecha() {
Serial.println("Girando a la derecha");
digitalWrite(m1_sta1, LOW);
digitalWrite(m1_sta2, HIGH);
}

void detenerDireccion() {
Serial.println("Deteniendo dirección");
digitalWrite(m1_sta1, LOW);
digitalWrite(m1_sta2, LOW);
}

void acelerar() {
if (retrocediendo) {
Serial.println("No se puede acelerar mientras retrocede. Detén el motor primero.");
return;
}

Serial.println("Acelerando...");
digitalWrite(m2_sta1, HIGH);
digitalWrite(m2_sta2, LOW);

if (velocidad < velocidadMin) {
velocidad = velocidadMin;
}

analogWrite(m2_pwm, velocidadMax);
enMovimiento = true;
retrocediendo = false;
}

void desacelerar() {
if (enMovimiento) {
Serial.println("Detén el motor antes de retroceder.");
detenerArranque();
delay(500);
}

Serial.println("Retrocediendo...");
digitalWrite(m2_sta1, LOW);
digitalWrite(m2_sta2, HIGH);

if (velocidad < velocidadMin) {
velocidad = velocidadMin;
}

analogWrite(m2_pwm, velocidadMax);
retrocediendo = true;
enMovimiento = false;
}

void detenerArranque() {
Serial.println("Deteniendo motor...");
velocidad = 0;
analogWrite(m2_pwm, velocidad);
digitalWrite(m2_sta1, LOW);
digitalWrite(m2_sta2, LOW);

enMovimiento = false;
retrocediendo = false;
}

void encenderLuces() {
Serial.println("Encendiendo luces");
digitalWrite(luzPin, HIGH);
}

void apagarLuces() {
Serial.println("Apagando luces");
digitalWrite(luzPin, LOW);
}
