#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
#define in 3
#define out 4
int count = 0;
void setup()
{
 lcd.begin(16,2);
 lcd.print("student Counter");
 delay(1000);
 pinMode(in,INPUT);
 pinMode(out,INPUT);
 lcd.clear();
}
void loop()
{  
 int in_value = digitalRead(in);
 int out_value = digitalRead(out);
 if(in_value == LOW)
 {
   count++;
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
 { lcd.clear();  
   lcd.clear();
   lcd.print("Nobody In class");
   lcd.setCursor(0,1);
   delay(1000);   }
else
{   }  }
