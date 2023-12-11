#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
#define in 3
#define out 4
#define relay 7
const int IN1= 5;
const int IN2= 6;
int count = 0;
void setup()
{
 lcd.begin(16,2);
 lcd.print("Visitor Counter");
 delay(1000);
 pinMode(in,INPUT);
 pinMode(out,INPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(relay,OUTPUT);  
}
void loop()
{  
int in_value = digitalRead(in);
 int out_value = digitalRead(out);
 
 if(in_value == LOW)
 {
   count++;
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   lcd.clear();
   lcd.print("Person In Room:");
   lcd.setCursor(0,1);
   lcd.print(count);
   delay( 1000);
 }                                                        
if(out_value == LOW) 
 {
   count--;
   lcd.clear();
   lcd.print("Person In Room:");
   lcd.setCursor(0,1);
   lcd.print(count);
   delay(1000);
 }
if(count==0)
 {
   lcd.clear();
   digitalWrite(relay,LOW);
   digitalWrite(IN1,LOW);
    digitalWrite(IN2, LOW);
   lcd.clear();
   lcd.print("Nobody In Room");
   lcd.setCursor(0,1);
   lcd.print("Light is Off");
   delay(1000);
 }                                      
else
 {
   digitalWrite(relay,HIGH);    
 }  }
