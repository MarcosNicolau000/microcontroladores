// NOMEANDO CONSTANTES

#define POT_INPUT A0
#define LED_VERM 2
#define LED_AMAR 3
#define LED_VERD 4
#define LED_AZUL 5

// DECLARAÇÃO DE VARIÁVEL

int potValue;

void setup() {
  pinMode(POT_INPUT, INPUT);
  pinMode(LED_VERM, OUTPUT);
  pinMode(LED_VERD, OUTPUT);
  pinMode(LED_AMAR, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
}


void loop() {
  potValue = analogRead(POT_INPUT);

  // FAIXA DE VALORES CORRESPONDE A DIVISÃO APROXIMADA DE 1023/4

  if (potValue < 255) { 
    acenderLedAzul();
  } else if (potValue < 510) {
    acenderLedVerde();
  } else if (potValue < 765){
    acenderLedAmarelo();
  } else {
    acenderLedVermelho();
  }
}

// FUNÇÕES PARA MELHORAR LEGIBILIDADE NO VOID LOOP

void acenderLedVermelho() {
  digitalWrite(LED_VERM, HIGH);
  digitalWrite(LED_AMAR, LOW);
  digitalWrite(LED_VERD, LOW);
  digitalWrite(LED_AZUL, LOW);

}
void acenderLedVerde() {
  digitalWrite(LED_VERM, LOW);
  digitalWrite(LED_AMAR, LOW);
  digitalWrite(LED_VERD, HIGH);
  digitalWrite(LED_AZUL, LOW);

}
void acenderLedAmarelo() {
  digitalWrite(LED_VERM, LOW);
  digitalWrite(LED_AMAR, HIGH);
  digitalWrite(LED_VERD, LOW);
  digitalWrite(LED_AZUL, LOW);
}

void acenderLedAzul() {
  digitalWrite(LED_VERM, LOW);
  digitalWrite(LED_VERD, LOW);
  digitalWrite(LED_AMAR, LOW);
  digitalWrite(LED_AZUL, HIGH);
}

