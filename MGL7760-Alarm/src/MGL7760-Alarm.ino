/*
 * Project MGL7760-Alarm
 * Description: TP3
 * Author: Hugo Hernan Ruiz 
 * Date: 17-04-2020 
 */

//#include <Adafruit_DHT.h>
#include <Adafruit_DHT_Particle.h>

#include <GlobalVariables.h>
#include <GlobalFunctions.h>

#include <FiniteStateMachine.h>
#include <FSM_Alarm.h>

#include <FSM_Vars.h>

// test Git Synchronization 

// setup() runs once, when the device is first turned on.
void setup() {
  
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(ledPin, OUTPUT);      // declare LED as output
  
  Serial.begin(9600);
 	dht.begin();

  Particle.function("Alarm_OnOff", Alarm_OnOff);
  Particle.function("Vars_OnOff", Vars_OnOff);
  
  Particle.variable("varStatus", varStatus);
  Particle.variable("alarmStatus", alarmStatus);



}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  
  //val = digitalRead(inputPin);  // read input value

  FSM_Alarm.update();
  FSM_Vars.update();

}


