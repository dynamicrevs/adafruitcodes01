#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X20,16,2); 
int LDR=A0,L1=8,LV;
void setup() {
lcd.begin();
pinMode(LDR,INPUT);
pinMode(L1,OUTPUT);
Serial.begin(9600);
delay(100);
}
void loop() {
LV=analogRead(LDR);
Serial.println(LV);
delay(100);
if(LV>100)
{
digitalWrite(L1, LOW);
lcd.setCursor(0,0);
lcd.print("DAY");
lcd.setCursor(0,1);
lcd.print("Light OFF");
Serial.println("DAY");
delay(100);
lcd.clear();
}
else
{
digitalWrite(L1,HIGH);
lcd.setCursor(0,0);
lcd.print("NIGHT");
lcd.setCursor(0,1);
lcd.print("Light ON");
Serial.println("NIGHT");
 delay(100);
lcd.clear();
}
}
