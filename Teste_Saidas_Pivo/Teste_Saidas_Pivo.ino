//bibliotecas
#include <SPI.h>
#include<SSD1306.h>

//Variável para controle do display
SSD1306 display(0x3c, 4, 15);

//*************PINOS DE SAÍDA DA PLACA *******************
const int pinoStart = 12;
const int pinoAvanco = 33;
const int pinoReversao = 32;
const int pinoBomba = 25;
const int pinoBbuster = 23;
const int pinoUltimaTorre = 22;
const int pinoAutomatico = 13;


//Configurações de setup do display
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
  Serial.begin(9600);
  setupDisplay();//Chama a função setup do display

  //Definimos os pinos como entrada ou saídas
  pinMode(pinoBomba, OUTPUT);
  pinMode(pinoBbuster, OUTPUT);
  pinMode(pinoUltimaTorre, OUTPUT);
  pinMode(pinoAvanco, OUTPUT);
  pinMode(pinoReversao, OUTPUT);
  pinMode(pinoStart, OUTPUT);
  pinMode(pinoAutomatico, OUTPUT);

  //Reset para desligar tudo na primeira execução
  digitalWrite(pinoAvanco, HIGH); // Avanço
  digitalWrite(pinoReversao, HIGH); // Reversão
  digitalWrite(pinoBomba, HIGH); // Bomba
  digitalWrite(pinoBbuster, HIGH); //BBuster
  digitalWrite(pinoUltimaTorre, HIGH); //BBuster
  digitalWrite(pinoStart, HIGH); //START
  digitalWrite(pinoAutomatico, HIGH); //START

}

void loop() {

  
  display.clear();
  display.drawString(0, 0,   "Iniciando Teste: " );
  display.display();

  delay(1000);

  display.clear();
  display.drawString(0, 0,   "Teste Rele1: " );
  display.drawString(0, 10,  "Saída Avanço " );
  display.display();

  delay(3000);
  
  digitalWrite(pinoAvanco, LOW); 
  delay(4000);
  digitalWrite(pinoAvanco, HIGH);
 
  delay(2000);

  display.clear();
  display.drawString(0, 0,   "Teste Rele2: " );
  display.drawString(0, 10,   "Saída Reversão " );
  display.display();

  delay(3000);

  digitalWrite(pinoReversao, LOW); 
  delay(4000);
  digitalWrite(pinoReversao, HIGH);

  delay(2000);

  display.clear();
  display.drawString(0, 0,   "Teste Rele3 : " );
  display.drawString(0, 10,   "Saída Bomba " );
  display.display();

  delay(3000);

  digitalWrite(pinoBomba, LOW); 
  delay(4000);
  digitalWrite(pinoBomba, HIGH);

  delay(2000);

  display.clear();
  display.drawString(0, 0,   "Teste Rele4: " );
  display.drawString(0, 10,   "Saída Bomba Booster " );
  display.display();

  delay(3000);

  digitalWrite(pinoBbuster, LOW); 
  delay(4000);
  digitalWrite(pinoBbuster, HIGH);

  delay(2000);

  display.clear();
  display.drawString(0, 0,   "Teste Rele5: " );
  display.drawString(0, 10,   "Saída ultima Torre " );
  display.display();

  delay(3000);

  digitalWrite(pinoUltimaTorre, LOW); 
  delay(4000);
  digitalWrite(pinoUltimaTorre, HIGH);

  delay(2000);

  display.clear();
  display.drawString(0, 0,   "Teste Rele6: " );
  display.drawString(0, 10,   "Saída modo automatico " );
  display.display();

  delay(3000);

  digitalWrite(pinoAutomatico, LOW); 
  delay(4000);
  digitalWrite(pinoAutomatico, HIGH);

  delay(2000);

  display.clear();
  display.drawString(0, 0,   "Teste Rele7: " );
  display.drawString(0, 10,   "Saída Start pivô " );
  display.display();

  delay(4000);
   
  digitalWrite(pinoStart, LOW); 
  delay(4000);
  digitalWrite(pinoStart, HIGH);

  delay(2000);

  display.clear();
  display.drawString(0, 0,   "Teste de Saidas Finalizado: " );
  display.display();

  delay(2000);
  

  
}
