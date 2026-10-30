#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

//* Configuracões do Acess Point
const char* SSID = "Esp32-Bruno";
const char* SENHA = "244466666";

WebServer servidorWeb(80);    //* instancia oum objeto para criar um WebServer

void setup() 
{
  Serial.begin(115200);
  
  WiFi.mode(WIFI_AP);   //* habilita o modo AP para criar uma rede WiFi
  WiFi.softAP(SSID, SENHA); //* cria a rede wifi

  Serial.println();
  Serial.println("---MODO AP ATIVO---");
  Serial.printf("Rede (SSID): %s\n\r", SSID);
  Serial.printf("Senha: %s\n\r", SENHA);
  Serial.printf("IP: %s\n\r", WiFi.softAPIP().toString().c_str());
  Serial.printf("Mac Address: %s\n\r", WiFi.softAPmacAddress().c_str());

  servidorWeb.begin();
}

void loop() 
{
  servidorWeb.handleClient();
}