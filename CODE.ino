#include <ESP32Servo.h>

#define AIN1 14
#define AIN2 27
#define PWMA 33

#define BIN1 26
#define BIN2 25
#define PWMB 32

#define STBY 12

#define TRIG 5
#define ECHO 18
#define SERVO_PIN 13

Servo myServo;

#define CHANNEL_A 0
#define CHANNEL_B 1
#define PWM_FREQ 1000
#define PWM_RES 8

void setup() {
  Serial.begin(115200);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  ledcSetup(CHANNEL_A, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWMA, CHANNEL_A);

  ledcSetup(CHANNEL_B, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWMB, CHANNEL_B);

  myServo.attach(SERVO_PIN);
  myServo.write(90);  // center position

  digitalWrite(STBY, HIGH);

  Serial.println("Bot Ready");
}

void loop() {
  int distance = readDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 15) {
    moveForward(255);  // max speed
  } else {
    stopMotors();
    delay(200);

    moveBackward(255); // max speed
    delay(400);
    stopMotors();
    delay(200);

    // Look left
    myServo.write(30);
    delay(400);
    int left = readDistance();
    Serial.print("Left: ");
    Serial.println(left);

    // Look right
    myServo.write(150);
    delay(400);
    int right = readDistance();
    Serial.print("Right: ");
    Serial.println(right);

    // Center
    myServo.write(90);
    delay(300);

    // Choose direction
    if (left > right) {
      turnLeft(255);  // max speed
      delay(500);
    } else {
      turnRight(255); // max speed
      delay(500);
    }

    stopMotors();
    delay(200);
  }

  delay(100); // Short pause to reduce CPU use
}

int readDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 20000); // Timeout at 20 ms
  int distance = duration * 0.034 / 2;

  if (distance == 0 || distance > 400) distance = 400;
  return distance;
}

void moveForward(int speed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  ledcWrite(CHANNEL_A, speed);
  ledcWrite(CHANNEL_B, speed);
}

void moveBackward(int speed) {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  ledcWrite(CHANNEL_A, speed);
  ledcWrite(CHANNEL_B, speed);
}

void turnLeft(int speed) {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  ledcWrite(CHANNEL_A, speed);
  ledcWrite(CHANNEL_B, speed);
}

void turnRight(int speed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  ledcWrite(CHANNEL_A, speed);
  ledcWrite(CHANNEL_B, speed);
}

void stopMotors() {
  ledcWrite(CHANNEL_A, 0);
  ledcWrite(CHANNEL_B, 0);
}

