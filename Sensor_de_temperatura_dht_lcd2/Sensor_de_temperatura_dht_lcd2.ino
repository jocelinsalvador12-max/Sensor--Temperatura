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

// Variable para controlar la alarma
bool alarmaActivada = false;

void setup() {

  lcd.init();
  lcd.backlight();

  dht.begin();

  Serial.begin(9600);

  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
}

void loop() {

  // Leer humedad y temperatura
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Verificar lectura
  if (isnan(h) || isnan(t)) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error lectura");

    return;
  }

  // Mostrar en LCD
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");

  // SI LA TEMPERATURA ES MAYOR O IGUAL A 40
  // Y LA ALARMA AUN NO HA SONADO
  if (t >= 40 && alarmaActivada == false) {

    alarmaActivada = true;

    // Sonar 3 veces
    for (int i = 0; i < 3; i++) {

      digitalWrite(LEDPIN, HIGH);

      tone(BUZZERPIN, 1000);

      delay(500);

      noTone(BUZZERPIN);

      digitalWrite(LEDPIN, LOW);

      delay(500);
    }
  }

  // Reiniciar alarma cuando baje la temperatura
  if (t < 40) {

    alarmaActivada = false;
  }

  delay(2000);
}
