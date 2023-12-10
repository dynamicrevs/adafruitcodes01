int trigpin = 2;
int echopin = 3;
long duration;
int distance;
int RIGHTMOTORFORWARD = 10; // in1 right motor forward
int RIGHTMOTORRIVERSE = 9; // in2 RIGHT motor REVERSE
int LEFTMOTORFORWARD = 8; // in3 LEFT MOTOR FORWARD
int LEFTMOTORRIVERSE = 7; //in4 left motor REVERSE
 void setup(){
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(RIGHTMOTORFORWARD, OUTPUT);
pinMode(LEFTMOTORFORWARD, OUTPUT);
pinMode(RIGHTMOTORRIVERSE, OUTPUT);
pinMode(LEFTMOTORRIVERSE, OUTPUT);
Serial.begin(9600);
}
void loop(){
digitalWrite(trigpin, LOW);//generate a pulse on
Trigger pin of ultrasonic sensor module
delayMicroseconds(3);
digitalWrite(trigpin, HIGH);
delayMicroseconds(11);
digitalWrite(trigpin, LOW);
duration = pulseIn(echopin, HIGH);
distance = duration * 0.034 / 2;
Serial.print("DISTANCE IN CM");
Serial.println(distance);
if((distance >= 10)&&(distance <= 50)){
digitalWrite(RIGHTMOTORRIVERSE, LOW);
digitalWrite(LEFTMOTORRIVERSE, LOW);
digitalWrite(RIGHTMOTORFORWARD, HIGH);
digitalWrite(LEFTMOTORFORWARD, HIGH);
}
else{
digitalWrite(RIGHTMOTORRIVERSE, LOW);
digitalWrite(LEFTMOTORRIVERSE, LOW);
digitalWrite(RIGHTMOTORFORWARD, LOW);
digitalWrite(LEFTMOTORFORWARD, LOW);
}
}
