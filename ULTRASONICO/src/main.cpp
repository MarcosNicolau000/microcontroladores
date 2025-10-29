#include <Arduino.h>
#include <Ultrasonic.h>

#define BUZZER_PIN 9
#define TRIGGER_PIN 11
#define ECHO_PIN 10

#define LED_1 4
#define LED_2 5
#define LED_3 6
#define LED_4 7

Ultrasonic Sensor(TRIGGER_PIN, ECHO_PIN);

int distancia;

unsigned long int tempoAtual;

void bip(int tempo) {
    tone(BUZZER_PIN, 1000);
    delay(tempo);   
    noTone(BUZZER_PIN);
    delay(tempo);   
    
}

void distancia0() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  noTone(BUZZER_PIN);
}
void distancia1() {
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  bip(500);
}


void distancia2() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  bip(300);
}

void distancia3() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, LOW);
  bip(150);
}

void distancia4() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, HIGH);
  bip(50);
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

}

void loop() {

  distancia = Sensor.read();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");
if (distancia>= 30){
  distancia0();
} else if (distancia >= 20 && distancia < 30) {
      distancia1();
    } else if (distancia >= 10 && distancia < 20) {
      distancia2();
    } else if (distancia >= 5 && distancia < 10) {
      distancia3();
    } else if (distancia < 5) {
      distancia4();
  }

}


