#include <AFMotor.h>

//motors
AF_DCMotor motorL (2);
AF_DCMotor motorR (4);

const int lineR = 9;
const int lineL = A4;


const int trigF = A0;
const int echoF = A1;


long durationF = 0;
int distanceF = 0;
int line_R = 0;
int line_L = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lineR, INPUT);
  pinMode(lineL, INPUT);
  pinMode(trigF, OUTPUT);
  pinMode(echoF, INPUT);
  delay(5000);
}

void fight(){
  line_R = digitalRead(lineR);
  line_L = digitalRead(lineL);
  
  digitalWrite(trigF, LOW);
  delayMicroseconds(2);
  digitalWrite(trigF, HIGH);
  durationF = pulseIn(echoF, HIGH);
  distanceF = durationF * 0.034 /2; //ultrasonicleft

  

  if(line_L == LOW || line_R == LOW){
    motorL.setSpeed(255);
    motorR.setSpeed(180);
    motorL.run(FORWARD);
    motorR.run(BACKWARD);
    delay(10);
  }

  if(line_L == HIGH && line_R == HIGH){
    if(distanceF <= 50){
      motorL.setSpeed(255);
      motorR.setSpeed(255);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
    }else{
      motorL.setSpeed(200);
      motorR.setSpeed(200);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
    }
  }
  
  Serial.print(line_L);
  Serial.print("\t");
  Serial.print(line_R);
  Serial.print("\t");
  //Serial.print(distanceIR);
  Serial.print("\tUtraLL");
  Serial.println(distanceF);
}

void loop() {
  // put your main code here, to run repeatedly:
  fight();
}
