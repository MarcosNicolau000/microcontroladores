// NOMEANDO CONSTANTES

#define POT_INPUT A0
#define LED_VERM 2

// DECLARAÇÃO DE VARIÁVEL

int potValue;

void setup() {
  pinMode(POT_INPUT, INPUT);
  pinMode(LED_VERM, OUTPUT);
}

void loop() {
  potValue = analogRead(POT_INPUT);
 
  // VARIAÇÃO DE VELOCIDADE SE O POTENCIÔMETRO ESTIVER MAIOR OU MENOR QUE 50%

  if (potValue < 1023*0.5) {
    digitalWrite(LED_VERM, HIGH);
    delay(1000);
    digitalWrite(LED_VERM, LOW);
    delay(1000);
  } else {
    digitalWrite(LED_VERM, HIGH);
    delay(500);
    digitalWrite(LED_VERM, LOW);
    delay(500);
  }
}


