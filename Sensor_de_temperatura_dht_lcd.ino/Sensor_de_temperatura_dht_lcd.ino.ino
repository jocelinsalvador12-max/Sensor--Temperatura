#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección del módulo I2C (puede ser 0x27 o 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorPin = A0;  // Pin donde está conectado el LM35

void setup() {
  lcd.init();        // Inicializa la pantalla
  lcd.backlight();   // Enciende la luz de fondo
  Serial.begin(9600);
}

void loop() {
  // Leer el valor analógico del LM35
  int lectura = analogRead(sensorPin);
  
  // Convertir a voltaje
  float voltaje = lectura * (5.0 / 1023.0);
  
  // Convertir voltaje a temperatura en °C (10mV por cada grado)
  float temperaturaC = voltaje * 100.0;

  // Mostrar en LCD
  lcd.clear();
  lcd.setCursor(0, 0);   // Primera fila
  lcd.print("Temp:");
  lcd.print(temperaturaC);
  lcd.print(" C");

  // Mostrar también en Serial
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" °C");

  delay(1000); // Espera 1 segundo antes de la siguiente lectura
}
