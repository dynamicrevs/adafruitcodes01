int LAMP=13;
int soundpin=A2;
int threshold=50;
int TEMP=0;
int soundsens=0;
void setup(){
Serial.begin(9600);
pinMode(LAMP,OUTPUT); 
pinMode(soundpin,INPUT);
}
void loop()
{
soundsens=analogRead(soundpin);
Serial.println(soundsens);
if(soundsens>threshold)
{
TEMP=~TEMP;
digitalWrite(LAMP,TEMP);
}
delay(500);
}
