#include <Adafruit_Fingerprint.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#define laser 4
#define centralock 5
#define buzzer 6
#define alarm 7
#define centralalarm 8
#define RST_PIN 9
#define SS_PIN 10
#define laseralarm 15
int locksensor = A0;
int alarmsensor = A2;
LiquidCrystal_I2C lcd(0x3F, 16, 2);
SoftwareSerial fingerSensor(2, 3);
MFRC522 mfrc522(SS_PIN, RST_PIN);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&fingerSensor);
int getFingerprintIDez();
uint8_t getFingerprintEnroll(int id);
uint8_t id;
void setup() {
  pinMode(locksensor, INPUT_PULLUP);
  pinMode(alarmsensor, INPUT_PULLUP);
  tone(buzzer, 1000, 500);
  pinMode(alarm, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(laseralarm, OUTPUT);
  pinMode(centralock, OUTPUT);
  pinMode(centralalarm, OUTPUT);
  digitalWrite(laseralarm, HIGH);
  digitalWrite(alarm, HIGH);
  digitalWrite(centralalarm, HIGH);
  digitalWrite(laser, LOW);
  digitalWrite(centralock, HIGH);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin();
  lcd.backlight();
  lcd.print("Please Wait.....");
  delay(2000);
  lcd.clear();
  lcd.print("Checking  Sensor");
  delay(1000);
  finger.begin(57600);
  if (finger.verifyPassword()) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fingerprint OK");
    lcd.setCursor(0, 1);
    lcd.print("RFID        OK");
    delay(1000);
  } else {
    lcd.clear();
    lcd.print("No Sensor");
    lcd.setCursor(0, 1);
    lcd.print("Check Connection");
    while (1);
  }
  startup();
  Serial.begin(9600);
}
void loop() {
  digitalWrite(centralalarm, HIGH);
  digitalWrite(laser, HIGH);
  if (digitalRead(locksensor) == HIGH) {
    digitalWrite(centralock, HIGH);
    digitalWrite(centralalarm, HIGH);
    digitalWrite(alarm, HIGH);
  }
  if (digitalRead(alarmsensor) == HIGH) {
    digitalWrite(centralalarm, LOW);
  }
  lcd.setCursor(0, 0);
  lcd.print("   Smart Home   ");
  lcd.setCursor(0, 1);
  lcd.print("  Security IoT  ");
  TapID();
  delay(1000);
}


