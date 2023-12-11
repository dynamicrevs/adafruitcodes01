int Sumpsensor = 3;      // Sump water level sensor
int Lower_sensor1 = 4;   // Tank water low level sensor
int Upper_sensor2 = 5;   // Tank water upper level sensor
int Motor = 6;     // Motor relay (output to control the motor)
int Sump_status = 0;     // Variable to store sump water level status
int LS = 1;       // Variable to store tank lower sensor status
int HS = 1;       // Variable to store tank upper sensor status
int motorstatus = 0;     // Variable to store motor status (0 - OFF, 1 - ON)

void setup() {
  pinMode(Sumpsensor, INPUT);
  pinMode(Lower_sensor1, INPUT);
  pinMode(Upper_sensor2, INPUT);
  pinMode(Motor_relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Sump_status = digitalRead(Sumpsensor);
  LS = digitalRead(Lower_sensor1);
  HS = digitalRead(Upper_sensor2);

  if (Sump_status == 1) 
  {  
    if ((LS == 0) && (HS == 0)) 
    {  
      digitalWrite(Motor, HIGH);
      motorstatus = 1;
      Serial.println("MOTOR IS ON");
    }
  }

  if (motorstatus == 1) {
    if ((LS == 1) && (HS == 1)) {  /
      digitalWrite(Motor, LOW);
      motorstatus = 0;
      Serial.println("Motor is off");
    }
  }

  delay(1000);  
