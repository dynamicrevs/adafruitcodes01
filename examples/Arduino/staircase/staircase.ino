int SWITCH1=4; /* Lower floor switch */
int SWITCH2=5; /* Upper floor switch */
int LAMP=6; /* Stair case Lamp*/
int TEMP1=0;
int TEMP2=0;
int TEMP3=0;
void setup()
{
pinMode(SWITCH1,INPUT);
pinMode(SWITCH2,INPUT);
pinMode(LAMP,OUTPUT);
}
void loop()
{
TEMP1=digitalRead(SWITCH1);
TEMP2=digitalRead(SWITCH2);
TEMP3= (TEMP1 ^ TEMP2);
digitalWrite(LAMP,TEMP3);
}
