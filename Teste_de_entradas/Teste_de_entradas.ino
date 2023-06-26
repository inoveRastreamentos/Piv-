//Bibliotecas
#include <SSD1306.h>

//*****Variável para controlar o display*****
SSD1306 display(0x3c, 4, 15);


//PINOS DE ENTRADA
const int pinoPressostato = 36; //Entrada positiva
const int pinoEnergia = 38; // Entrada Positiva
const int pinoSeguranca = 21; //Entrada negativa
const int pinoAnalogico = 37; // Entrada negativa

//Variaveis que recebem o valor dos pinos
int monitorPressostato = 0;
int monitorEnergia = 0;
int monitorSeguranca = 0;
int monitorAnalogico = 0;

void setupDisplay() {
  //O estado do GPIO16 é utilizado para controlar o display OLED
  pinMode(16, OUTPUT);
  //Reseta as configurações do display OLED
  digitalWrite(16, LOW);
  //Para o OLED permanecer ligado, o GPIO16 deve permanecer HIGH
  //Deve estar em HIGH antes de chamar o display.init() e fazer as demais configurações,
  //não inverta a ordem
  digitalWrite(16, HIGH);

  //Configurações do display
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
}


void setup() {
  setupDisplay();
  pinMode(pinoPressostato, INPUT);
  pinMode(pinoEnergia, INPUT);
  pinMode(pinoAnalogico, INPUT);
  pinMode(pinoSeguranca, INPUT);

}

void loop() {
   monitorPressostato = digitalRead(pinoPressostato);
   monitorEnergia = digitalRead(pinoEnergia);
   monitorSeguranca = digitalRead(pinoSeguranca);
   monitorAnalogico = digitalRead(pinoAnalogico);

   display.clear();
   display.drawString(0,0,"Testando Entradas");
   display.drawString(0,10,"Entrada Pressostato: " + (String)monitorPressostato);
   display.drawString(0,20,"Entrada Energia: " + (String)monitorEnergia);
   display.drawString(0,30,"Entrada Segurança: " + (String)monitorSeguranca);
   display.drawString(0,40,"Entrada Analogica: " + (String)monitorAnalogico);
   display.display();
}
