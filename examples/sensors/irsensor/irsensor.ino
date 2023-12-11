int IRstate=0;
void setup()    
{
Serial.begin(9600);
pinMode(7,INPUT);
pinMode(6,OUTPUT);
int IRstate=0;
}
void loop()
 {
IRstate=digitalRead(7);
if (IRstate==0)
{
digitalWrite (6,HIGH);
Serial.println("object is detected");
}
else
{
digitalWrite (6,LOW);
Serial.println("object is not detected");
}
delay(1000);
}
