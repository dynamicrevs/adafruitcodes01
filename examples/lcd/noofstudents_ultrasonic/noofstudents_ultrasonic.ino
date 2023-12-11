#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin1 = 7;
const int echoPin1 = 8;
const int trigPin2 = 9;
const int echoPin2 = 10;
const int ledPin = 11;

const int maxCount = 60;
const int objectDetectTime = 500;
const int countGapTime = 2000;

const int exitCountThreshold = 10;
unsigned long entrySensorTime = 0;
unsigned long exitSensorTime = 0;
unsigned long lastExitCountTime = 0;
unsigned long lastCountTime = 0;
bool entrySensorActive = true;
bool objectCounted = false;
bool exitSensorActive = false;

int objectCount = 0;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.print("Object Count: ");
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration1, duration2;
  int distance1, distance2;

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  if (distance1 < 10 && entrySensorActive) {
    if (entrySensorTime == 0) {
      entrySensorTime = millis();
    } else if (millis() - entrySensorTime >= objectDetectTime) {
      if (!objectCounted && (millis() - lastCountTime >= countGapTime)) {
        objectCount = min(maxCount, objectCount + 1);
        entrySensorTime = millis();
        lastCountTime = millis();
        objectCounted = true;
      }
    }
  } else {
    entrySensorTime = 0;
    objectCounted = false;
  }

  if (distance2 < 10 && objectCount > 0) {
    if (!exitSensorActive) {
      exitSensorTime = millis();
      exitSensorActive = true;
    } else if (millis() - exitSensorTime >= objectDetectTime) {
      if (millis() - lastExitCountTime >= countGapTime) {
        objectCount = max(0, objectCount - 1);
        lastExitCountTime = millis();
      }
      exitSensorActive = false;
    }
  } else {
    exitSensorActive = false;
  }

  lcd.setCursor(14, 0);
  lcd.print(objectCount);

  if (objectCount > 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
