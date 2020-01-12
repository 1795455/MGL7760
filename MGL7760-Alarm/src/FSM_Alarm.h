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


void Alarm_OffStt_Enter()
{
	sprintf(Alarm_CurrentStt, "Alarm_OFF_STT");
	Serial.println(" Enter Alarm_OffStt ...");

}

void Alarm_OffStt_Update()
{
    Serial.printlnf("\n Count Value: %d", count++);
    delay(500);
}
void Alarm_OffStt_Exit()
{
	Serial.println(" Exit Alarm_OffStt ...");
}

void Alarm_OnStt_Enter()
{
	sprintf(Alarm_CurrentStt, "Alarm_On_STT");
	Serial.println(" Enter Alarm_OnStt ...");

}

void Alarm_OnStt_Update()
{

}
void Alarm_OnStt_Exit()
{
	Serial.println(" Exit Alarm_OnStt ...");
}