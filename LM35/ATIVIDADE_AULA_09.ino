#include <LiquidCrystal.h>

#define LM35_PIN A0

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

void setup() {
    lcd.begin(16, 2);
    lcd.print("TEMP: ");
    lcd.setCursor(0, 1); 
    lcd.clear();
}

float lerTemperatura() {
    float valorADC = analogRead(LM35_PIN);
    float tensao = (valorADC * 5) / 1023;
    float temperatura = tensao / 0.01;
    return temperatura;
}

void imprimirLcd(float val) {
    lcd.print(val);
}

void loop() {
    float temperatura;
    temperatura = lerTemperatura();
    imprimirLcd(temperatura);
    delay(1000);
}