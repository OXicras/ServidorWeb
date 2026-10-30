#include <Arduino.h>
#include <WiFi.h>

//* Configuracões do Acess Point
const char* SSID = "Esp32-Bruno";
const char* SENHA = "244466666";

void setup() 
{
  Serial.begin(115200);
  
  WiFi.mode(WIFI_AP);   //* habilita o modo AP para criar uma rede WiFi
  WiFi.softAP(SSID, SENHA); //* cria a rede wifi
}

void loop() 
{
  
}