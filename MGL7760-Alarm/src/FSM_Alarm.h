// FSM_Alarm States
//-------------------------------------------------------------------------------

void Alarm_OffStt_Enter();
void Alarm_OffStt_Update();
void Alarm_OffStt_Exit();

void Alarm_OnStt_Enter();
void Alarm_OnStt_Update();
void Alarm_OnStt_Exit();

State Alarm_OFF_STT = State(Alarm_OffStt_Enter, Alarm_OffStt_Update, Alarm_OffStt_Exit);
State Alarm_ON_STT = State(Alarm_OnStt_Enter, Alarm_OnStt_Update, Alarm_OnStt_Exit);

FSM FSM_Alarm = FSM(Alarm_OFF_STT);
char Alarm_CurrentStt[32];

int lastMillis;


void Alarm_OffStt_Enter()
{
	sprintf(Alarm_CurrentStt, "Alarm_OFF_STT");
	Serial.println(" Enter Alarm_OffStt ...");

    lastMillis=millis();

}

void Alarm_OffStt_Update()
{
    if (alarmStatus == 0)
    {
        if (millis()-lastMillis >= 1000){Serial.printlnf("\n Alarm OFF: %d", count++);lastMillis=millis();}

    }else{
        FSM_Alarm.transitionTo(Alarm_ON_STT);
    }

}
void Alarm_OffStt_Exit()
{
	Serial.println(" Exit Alarm_OffStt ...");
    count=0;
}

void Alarm_OnStt_Enter()
{
        sprintf(Alarm_CurrentStt, "Alarm_On_STT");
	    Serial.println(" Enter Alarm_OnStt ...");

        lastMillis=millis();
}

void Alarm_OnStt_Update()
{

    if (millis()-lastMillis >= 1000){Serial.printlnf("\n Alarm On: %d", count++);lastMillis=millis();}

    if (alarmStatus == 1)
    {    
        //Serial.printlnf("\n Alarm On: %d", count++);
        //delay(1000);

        val = digitalRead(inputPin);  // read input value
        if (val == HIGH) {            // check if the input is HIGH
            digitalWrite(ledPin, HIGH);  // turn LED ON
            if (pirState == LOW) {
                // we have just turned on
                Serial.println("Motion detected!");
                // We only want to print on the output change, not state
                pirState = HIGH;
            }
        } else {
            digitalWrite(ledPin, LOW); // turn LED OFF
            if (pirState == HIGH){
            // we have just turned of
            Serial.println("Motion ended!");
            // We only want to print on the output change, not state
            pirState = LOW;
        }
  }


    }else{
        FSM_Alarm.transitionTo(Alarm_OFF_STT);
    }
}
void Alarm_OnStt_Exit()
{
	Serial.println(" Exit Alarm_OnStt ...");
    count=0;
}