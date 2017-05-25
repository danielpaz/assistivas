int onboardLED = 13; // Arduino onboard LED (pin 13) you can control
int voltageThreshold = 100; // any reading higher will trigger an action

#include "Keyboard.h"

void setup() {
  // put your setup code here, to run when Arduino is powered on:
  Serial.begin(9600);
  pinMode(onboardLED, OUTPUT);
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //voltageThreshold = analogRead(A0); //reads from potenciometer
  int currentVoltage = analogRead(A0); // store the incoming voltage 
  Serial.println(currentVoltage);       // prints voltage to monitor
  if(currentVoltage >= voltageThreshold){
     // trigger actions
     Serial.println("CONTRACTION!");  // prints string + new line
     digitalWrite(onboardLED, HIGH); //this sends 5V, turning on LED
     Keyboard.write(KEY_F12);
     //Keyboard.write('c');
     //delay(500);
  } else {
     //Serial.println(""); // adds a new line
     digitalWrite(onboardLED, LOW); 
     //delay(500);
     // turn off the light if threshold is not met
  }
  //digitalWrite(onboardLED, HIGH);
  delay(500);
}

