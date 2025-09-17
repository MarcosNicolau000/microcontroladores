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

  // FAIXA DE VALORES 
  // 0 <= potValue < 255        -> VALOR BAIXO
  // 255 <= potValue < 765      -> VALOR INTERMEDIÁRIO
  // 765 <= potValue < 1023     -> VALOR ALTO
  // potValue = 1023            -> VALOR MÁXIMO


  if (potValue < 255) { 
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_VERM, LOW);
    digitalWrite(LED_AMAR, LOW);
    digitalWrite(LED_VERD, LOW);
  } else if (potValue < 765){
    digitalWrite(LED_VERD, HIGH);
    digitalWrite(LED_VERM, LOW);
    digitalWrite(LED_AMAR, LOW);
  } else if (potValue < 1023){
    digitalWrite(LED_AMAR, HIGH);
    digitalWrite(LED_VERM, LOW);
  } else {
    digitalWrite(LED_VERM, HIGH);
  }
}

