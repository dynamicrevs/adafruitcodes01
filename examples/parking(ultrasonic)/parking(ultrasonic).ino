#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensor1Trigger = 7;
int sensor1Echo = 8;
int sensor2Trigger = 9;
int sensor2Echo = 10;
int maxSlots = 2;
bool slot1Occupied = false;
bool slot2Occupied = false;
bool bothSlotsFull = false;

void setup() {
  servo.attach(11);
  pinMode(sensor1Trigger, OUTPUT);
  pinMode(sensor1Echo, INPUT);
  pinMode(sensor2Trigger, OUTPUT);
  pinMode(sensor2Echo, INPUT);
  
  lcd.begin();
  lcd.backlight();

  servo.write(180);
  
  lcd.print("Slot 1: Empty");
  lcd.setCursor(0, 1);
  lcd.print("Slot 2: Empty");
}

void loop() {
  int distance1 = measureDistance(sensor1Trigger, sensor1Echo);
  int distance2 = measureDistance(sensor2Trigger, sensor2Echo);

  if (distance1 >= 1 && distance1 <= 5) {
    if (!slot1Occupied) {
      lcd.setCursor(7, 0);
      lcd.print("Full");
      slot1Occupied = true;
    }
  } else {
    if (slot1Occupied) {
      lcd.setCursor(7, 0);
      lcd.print("Empty");
      slot1Occupied = false;
    }
  }

  if (distance2 >= 1 && distance2 <= 5) {
    if (!slot2Occupied) {
      lcd.setCursor(7, 1);
      lcd.print("Full");
      slot2Occupied = true;
    }
  } else {
    if (slot2Occupied) {
      lcd.setCursor(7, 1);
      lcd.print("Empty");
      slot2Occupied = false;
    }
  }

  bothSlotsFull = slot1Occupied && slot2Occupied;

  if (bothSlotsFull) {
    servo.write(90);
  } else {
    servo.write(180);
  }

  delay(100);
}

int measureDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH) / 58;
}
