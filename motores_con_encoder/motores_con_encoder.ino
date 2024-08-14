#define DIR1 4
#define PWM1 5

#define encoderPinA 2
#define encoderPinB 3

volatile long encoderCount = 0;

void setup() {
  Serial.begin(9600);

  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoder, RISING);
}

void loop() {
  // Mueve el motor
  moveMotor(DIR1, PWM1, 200);  // Ajusta la velocidad si es necesario

  // Espera y muestra el valor del encoder durante 2 segundos
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    Serial.print("Encoder Count: ");
    Serial.println(encoderCount);
    delay(100);  // Muestra el valor cada 100ms
  }

  // Detén el motor
  moveMotor(DIR1, PWM1, 0);

  // Espera 2 segundos antes de volver a mover el motor
  delay(2000);
}

void handleEncoder() {
  if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
    encoderCount++;
  } else {
    encoderCount--;
  }
}

void moveMotor(int dirPin, int pwmPin, float u) {
  float speed = fabs(u);
  if (speed > 255) {
    speed = 255;
  }

  int direction = (u >= 0) ? HIGH : LOW;

  digitalWrite(dirPin, direction);
  analogWrite(pwmPin, speed);
}
