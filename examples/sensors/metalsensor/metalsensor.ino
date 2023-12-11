int TEMP=0;
int count=0;
void setup()
{
pinMode(8,INPUT);
pinMode(2,OUTPUT);
Serial.begin(9600);
}
void loop()
{
TEMP=digitalRead(8);
if(TEMP==1)
{
digitalWrite(2,HIGH);
count=count+1;
}
else digitalWrite(2,LOW);
Serial.print("Total metals detected:");
Serial.println(count);
delay(1000);
}
