// DECLARAÇÃO DE VARIÁVEIS GLOBAIS.

int leds[5] = {2,3,4,5,6};
bool estadosLed[5] = {true, true, true, true, true};
unsigned long tempoAnterior = 0;
int i = 0;
bool sentido = true;

void setup() {
    
  // INCIALIZAÇÃO DOS PINOS DOS LEDS
  for (i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  i = 0;
}

void loop() {

  // VERIFICAÇÃO DE TEMPO COM MILLIS()
  unsigned long tempoAtual = millis();
  if (tempoAtual - tempoAnterior >= 100) {

    // TROCA DE ESTADO DO LED
    digitalWrite(leds[i], estadosLed[i]);
    estadosLed[i] = !estadosLed[i];

    // ATUALIZAÇÃO DO ITERADOR
  
    if (sentido == true) {
        if (i == 5) {
        	sentido = false;
            
        } else {
            i++;
        }

    } 
    if (sentido == false){
        if (i == 0) {
      	    sentido = true;
        } else {
            i--;
        }
    }

    // ATUALIZAÇÃO PARA FUNCIONAMENTO DO MILLIS()
    tempoAnterior = millis();
  } 
}
