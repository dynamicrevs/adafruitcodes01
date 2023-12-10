int VIB_CHECK=8;
int BUZZER=9;
int HIT;
voidsetup()
{
pinMode(VIB_CHECK,INPUT);
pinMode(BUZZER,OUTPUT);
}
voidloop()
{ HIT=digitalRead(VIB_CHECK);
if(HIT==1)
{
digitalWrite(BUZZER,HIGH);
delay(10000);
}
else
digitalWrite(BUZZER,LOW);
}
