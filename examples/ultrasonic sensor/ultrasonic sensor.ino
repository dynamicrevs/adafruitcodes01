int trigpin=2;
int echopin=3;
long duration;
int distance;
int BUZZER=10;
void setup() {  
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(BUZZER,OUTPUT);
Serial.begin(9600);
}
void loop() {
digitalWrite(trigpin,LOW);
delayMicroseconds(3);
digitalWrite(trigpin,HIGH);
delayMicroseconds(11);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
distance=duration*0.034/2;
Serial.print("DISTANCE IN CM");
Serial.println(distance);
if ((distance<=100))  {
digitalWrite(BUZZER,HIGH);
Serial.println("OBJECT IS DETECTED");
}  
else  {
digitalWrite(BUZZER,LOW);
Serial.println("OBJECT IS NOT DETECTED");
}  
delay(1000);  }
