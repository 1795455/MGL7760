
int Alarm_OnOff(String Args)
{
	alarmStatus=Args.toInt();
    if (alarmStatus == 0 || alarmStatus==1) Serial.printlnf("\n Command Alarm Value: %d", alarmStatus);
    else {Serial.printlnf("\n Error Alarm Value: %d", alarmStatus); alarmStatus=0;}
	
    return alarmStatus;
}


int Vars_OnOff(String Args)
{
	varStatus=Args.toInt();
    if (varStatus == 0 || varStatus==1) Serial.printlnf("\n Reading variables: %d", varStatus);
    else {Serial.printlnf("\n Error variables Value: %d", varStatus); varStatus=0;}
	
    return varStatus;
}