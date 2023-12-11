int Sumpsensor=3; /* sump water level sensor */
int Lower_sensor1=4; /* Tank water Low level sensor */
int Upper_sensor2=5; /*Tank water upper level sensor 8*/
int Motor_relay=6;
int Sump_status=0;
int LS_status=1;
int HS_status=1;
int motorstatus=0;
void setup() {
pinMode(Sumpsensor,INPUT);
pinMode(Lower_sensor1,INPUT);
pinMode(Upper_sensor2,INPUT);
pinMode(Motor_relay,OUTPUT);
Serial.begin(9600);
}
void loop() {
Sump_status=digitalRead(Sumpsensor);
LS_status =digitalRead(Lower_sensor1);
HS_status =digitalRead(Upper_sensor2);
if(Sump_status ==1) /* if the sump has water , check the tank sensors*/
if((LS_status ==0)&&( HS_status ==0)) /* Turn ON motor when tank fills*/
{
digitalWrite(Motor_relay,HIGH);
motorstatus=1;
Serial.println("MOTOR IS ON");
}
if (motorstatus==1)
if((LS_status ==1)&&(HS_status ==1)) /* Turn OFF motor when tank fills*/
{
digitalWrite(Motor_relay,LOW);
motorstatus=0;
Serial.println("Motor is off");
}
delay(1000);
}
