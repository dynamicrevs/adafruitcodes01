int START=4; /*Start switch*/
int STOP=5; /*Stop switch*/
int MOTOR=6; /*Motor or Lamp*/
int LATCH=0; /* Start/Stop switch Latch*/
int TEMP1=0; /*TEMP1 & TEMP2: variable to hold the status of the switches*/
int TEMP2=10;
void setup(){
pinMode(START,INPUT);
pinMode(STOP,INPUT);
pinMode(MOTOR,OUTPUT);
}
void loop()
{
TEMP1=digitalRead(START);
TEMP2=digitalRead(STOP);
if(TEMP1==1) /* CHECK IF THE START SWITCH IS PRESSED*/
LATCH =1;
if(TEMP2==1) /* CHECK IF THE START SWITCH IS PRESSED*/
LATCH =0;
digitalWrite(MOTOR,LATCH);
}
