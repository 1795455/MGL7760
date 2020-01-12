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



// setup() runs once, when the device is first turned on.
void setup() {
  
  Particle.function("Alarm_OnOff", Alarm_OnOff);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  
  FSM_Alarm.update();

}


