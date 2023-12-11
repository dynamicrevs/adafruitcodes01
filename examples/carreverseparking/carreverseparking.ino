int trigpin=2;
int echopin=3;
long duration;
int distance;
int BUZZER=10;
void setup()
{
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(BUZZER,OUTPUT);
Serial.begin(9600);
}
void loop()
{
digitalWrite(trigpin,LOW);
delayMicroseconds(3);
digitalWrite(trigpin,HIGH);
delayMicroseconds(11);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
Serial.println(echopin);
Serial.println(duration);
distance=duration*0.034/2;
Serial.print("DISTANCE IN CM");
Serial.println(distance); if((distance<=10))
digitalWrite(BUZZER,HIGH);
elseif((distance>10)&&(distance<=50))
{
digitalWrite(BUZZER,HIGH);
delay(100);
digitalWrite(BUZZER,LOW);
delay(100);
}
elseif((distance>50)&&(distance<=200))
{ digitalWrite(BUZZER,HIGH);
delay(500);
digitalWrite(BUZZER,LOW);
delay(500);
}
else digitalWrite(BUZZER,LOW);
}
