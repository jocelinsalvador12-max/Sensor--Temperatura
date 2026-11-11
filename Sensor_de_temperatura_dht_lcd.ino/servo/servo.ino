#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11

// Pines
#define LEDPIN 8
#define BUZZERPIN 9

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  lcd.init();
  lcd.backlight();

  dht.begin();

  Serial.begin(9600);

  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Verifica errores
  if (isnan(h) || isnan(t)) {

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error sensor");

    return;
  }

  // Mostrar datos en LCD
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");

  // ALARMA SI TEMPERATURA >= 40
  if (t >= 40) {

    digitalWrite(LEDPIN, HIGH);

    // Buzzer activo
    digitalWrite(BUZZERPIN, HIGH);

    delay(3000);

    digitalWrite(LEDPIN, LOW);

    digitalWrite(BUZZERPIN, LOW);
  }

  delay(2000);
}
