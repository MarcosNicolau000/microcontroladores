// DECLARAÇÃO DE CONSTANTE E VARIÁVEIS GLOBAIS.

#define LED_PIN 3

unsigned long tempoAnterior = 0;
int tempoEspera = 1000;
bool estadoAtual = false;

void setup() {
  // INCIALIZAÇÃO DOS PINOS DOS LEDS
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  // VERIFICAÇÃO DE TEMPO COM MILLIS()
  unsigned long tempoAtual = millis();
  if (tempoAtual - tempoAnterior >= tempoEspera) {

    // TROCA DE ESTADO DO LED
    digitalWrite(LED_PIN, estadoAtual);
    estadoAtual = !estadoAtual;

    // ATUALIZAÇÃO DO TEMPO

    tempoEspera -= 100;
    if (tempoEspera <= 0) tempoEspera = 1000;

    // ATUALIZAÇÃO PARA FUNCIONAMENTO DO MILLIS()
    tempoAnterior = tempoAtual;
  }
}
