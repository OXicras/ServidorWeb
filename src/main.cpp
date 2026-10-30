#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

//* Configuracões do Acess Point
const char* SSID = "Esp32-Bruno";
const char* SENHA = "244466666";

WebServer servidorWeb(80);    //* instancia oum objeto para criar um WebServer

void paginaInicial() //* Funcao para gerar a pagina HTML que aparece no navegador
{
    String status = digitalRead(48)? "Ligado" : "Desligado";
    String htmlTexto = 
    "<meta name ='viewport' content='width-device-width'>"
    "<p>LED: <b>"+ status +"</b></p>"
    "<a href='/on'><button>LIGAR</button></a>"
    "<a href='/off'><button>DESLIGAR</button></a>";

    servidorWeb.send(200, "text/html", htmlTexto);
}

void ligar()
{
  rgbLedWrite(48,255, 0, 0);
  paginaInicial();  
}

void desligar()
{
    rgbLedWrite(48, 0, 0, 0);
    paginaInicial();
}

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

  //ToDo ---- ROTAS ----
  //? Ensina o servidor qual a funcao chamar dependendo da url que o usuario acessar
  //? CRUD:          Comando HTTP

  //?       Create | Post;   
  //?       Read   | GET;   
  //?       Update | PUT;     
  //?       Delete | Delete.
  servidorWeb.on("/", paginaInicial);
  servidorWeb.on("/on", ligar);
  servidorWeb.on("/off", desligar);

  //* coloca o servidor no ar para comecar a receber conexoes
  servidorWeb.begin();
}

void loop() 
{
  servidorWeb.handleClient();
}