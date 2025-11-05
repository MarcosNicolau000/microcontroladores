#include <LiquidCrystal.h>

#define LM35_PIN A0
#define TEMP_LIMITE 50

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


// Função que lê a temperatura e converte para uma variável float
float lerTemperatura() {
  int valorADC = analogRead(LM35_PIN);
  float tensao = (valorADC * 5) / 1024.0;
  float temperatura = (tensao * 1000) / 10;
  return temperatura;
}

void setup() {
  lcd.begin(16,2);
  lcd.clear(); 
  Serial.begin(9600);
}

void loop() {
  float temperatura = lerTemperatura();

  // Impressão da temperatura no LCD
  lcd.setCursor(0, 0);
  lcd.print("TEMP: ");
  lcd.print(temperatura);
  lcd.print(" C   ");

  // Verificação se a temperatura superou o limite perigoso e exibição do display do status da temperatura
  lcd.setCursor(0, 1);
  if (temperatura >= TEMP_LIMITE) {
    lcd.print("!ALERTA QUENTE!");
  } else {
    lcd.print("Status: Normal     ");
  }
  Serial.println(temperatura);
  delay(1000);
}