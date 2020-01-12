/*
 * Project MGL7760-Alarm
 * Description: 
 * Author: Hugo Hernan Ruiz 
 * Date: 10-01-2020 
 */


#include <GlobalVariables.h>
#include <GlobalFunctions.h>

#include <FiniteStateMachine.h>
#include <FSM_Alarm.h>

// test Git Synchronization 

// setup() runs once, when the device is first turned on.
void setup() {
  
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(ledPin, OUTPUT);      // declare LED as output
  
  Serial.begin(9600);
 
  Particle.function("Alarm_OnOff", Alarm_OnOff);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  
  //val = digitalRead(inputPin);  // read input value

  FSM_Alarm.update();

}


