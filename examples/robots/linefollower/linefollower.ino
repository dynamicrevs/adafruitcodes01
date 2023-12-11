#define enA 10 // Enable1 L298 Pin enA
#define in1 9  // Motor1 L298 Pin in1
#define in2 8  // Motor1 L298 Pin in2
#define in3 7  // Motor2 L298 Pin in3
#define in4 6  // Motor2 L298 Pin in4
#define enB 5  // Enable2 L298 Pin enB
 
#define L_S A0 // Digital sensor for left
#define R_S A1 // Digital sensor for right
 
int Set = 260; // Adjust the threshold value as needed
 
void setup() {
  Serial.begin(9600); // start serial communication at 9600bps
 
  pinMode(enA, OUTPUT); // declare as output for L298 Pin enA
  pinMode(in1, OUTPUT); // declare as output for L298 Pin in1
  pinMode(in2, OUTPUT); // declare as output for L298 Pin in2
  pinMode(in3, OUTPUT); // declare as output for L298 Pin in3
  pinMode(in4, OUTPUT); // declare as output for L298 Pin in4
  pinMode(enB, OUTPUT); // declare as output for L298 Pin enB
 
  analogWrite(enA, 100); // Set the motor speed to 95%
  analogWrite(enB, 100); // Set the motor speed to 95%
 
  // Initialize your servo and other setup code if needed
}
 
void loop() {
  // Line Following Logic with Digital Sensors
  int leftSensorValue = digitalRead(L_S);
  int rightSensorValue = digitalRead(R_S);
 
  if (leftSensorValue == LOW && rightSensorValue == LOW) {
    forward();
  } else if (rightSensorValue == LOW && leftSensorValue == HIGH) {
    turnRight();
  } else if (leftSensorValue == LOW && rightSensorValue == HIGH) {
    turnLeft();
  } else {
    Stop();
  }
 
  delay(10);
}
 
void forward() {
  digitalWrite(in1, LOW);  // Left Motor forward (Reversed)
  digitalWrite(in2, HIGH); // Left Motor forward (Reversed)
  digitalWrite(in3, LOW);  // Right Motor forward (Reversed)
  digitalWrite(in4, HIGH); // Right Motor forward (Reversed)
}
 
void turnRight() {
  digitalWrite(in1, LOW);  // Left Motor forward
  digitalWrite(in2, HIGH); // Left Motor forward
  digitalWrite(in3, HIGH); // Right Motor forward
  digitalWrite(in4, LOW);  // Right Motor forward
}
 
void turnLeft() {
  digitalWrite(in1, HIGH); // Left Motor forward
  digitalWrite(in2, LOW);  // Left Motor forward
  digitalWrite(in3, LOW);  // Right Motor forward
  digitalWrite(in4, HIGH); // Right Motor forward
}
 
void Stop() {
  digitalWrite(in1, LOW);  // Left Motor stop
  digitalWrite(in2, LOW);  // Left Motor stop
  digitalWrite(in3, LOW);  // Right Motor stop
  digitalWrite(in4, LOW);  // Right Motor stop
}
 
