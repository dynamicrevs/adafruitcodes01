#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
int sensor1=2;
int sensor2=3;
int spot1=12;
int spot2=13;
int TEMP1=0;
int TEMP2=0;
int TEMP3=1;
int TEMP4=1;
int E_slots=0; /* Total slots Available for parking */
void setup() {
 lcd.begin(16,2);
pinMode(sensor1,INPUT);
pinMode(sensor2,INPUT);
pinMode(spot1,OUTPUT);
pinMode(spot2,OUTPUT);
Serial.begin(9600);
delay(100);
}
void loop() {
TEMP1=digitalRead(sensor1);
TEMP2=digitalRead(sensor2);
if(TEMP1^TEMP3==1)
{
TEMP3=TEMP1;
if(TEMP1==0) /* Check if a car Enters or leaves the slot1 */ 
{
E_slots=E_slots-1;
digitalWrite(spot1,HIGH);
}
else
{
E_slots=E_slots+1;
digitalWrite(spot1,LOW);
}
}
if(TEMP2^TEMP4==1)
{
TEMP4=TEMP2;
if(TEMP2==0) /* Check if a car Enters or leaves the slot2 */ 
{
E_slots=E_slots-1;
digitalWrite(spot2,HIGH);
}
else
{
E_slots=E_slots+1;
digitalWrite(spot2,LOW);
}
}
lcd.print("Number of Empty Slots:");
lcd.setCursor(0,1);
lcd.println(E_slots);
delay(100);
}
