#include <Stepper.h>

const int stepsPerRevolution = 200;  // cambie este valor por el numero de pasos de su motor

// inicializa la libreria 'stepper' en los pines 8 a 11
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

void setup() {
  // establece la velocidad en 60rpm
  myStepper.setSpeed(60);
  // inicializa el puerto serial
  Serial.begin(9600);
}

void loop() {
  // gira una vuelta en una direccion
   Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
   // gira otra vuelta en la otra direccion
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000); 
}