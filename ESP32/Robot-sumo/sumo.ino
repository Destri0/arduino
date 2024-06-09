/*
--Code develop by Fran
*/
#include <AFMotor.h> 
#include <NewPing.h> 

#define TRIGGER_PIN  2  
#define ECHO_PIN     3 
#define MAX_DISTANCIA 200 
#define IZQ_SENSOR_PIN A0 
#define DERE_SENSOR_PIN A1 
#define THRESHOLD 500
#define DISTANCIA_ENEMIGO 20

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCIA);
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  Serial.begin(9600);
  pinMode(IZQ_SENSOR_PIN, INPUT);
  pinMode(DERE_SENSOR_PIN, INPUT);
}

void loop() {
  int distancia = sonar.ping_cm();
  
  int valorsendorizq = analogRead(IZQ_SENSOR_PIN);
  int valorsendordere = analogRead(DERE_SENSOR_PIN);
  
  if (valorsendorizq < THRESHOLD) {
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  } else if (valorsendordere < THRESHOLD) {
    motor1.setSpeed(200);
    motor2.setSpeed(200);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  } else {
    if (distancia > 10 && distancia < 30) {
      motor1.setSpeed(200);
      motor2.setSpeed(200);
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      delay(1000);
      motor1.setSpeed(200);
      motor2.setSpeed(200);
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      delay(1000);
    } else {
      if (distancia < DISTANCIA_ENEMIGO) {
        motor1.setSpeed(200);
        motor2.setSpeed(200);
        motor1.run(FORWARD);
        motor2.run(FORWARD);
      } else {
        motor1.setSpeed(200);
        motor2.setSpeed(200);
        motor1.run(FORWARD);
        motor2.run(FORWARD);
      }
    }
  }
}
