
int Alarm_OnOff(String Args)
{
	alarmStatus=Args.toInt();
    if (alarmStatus == 0 || alarmStatus==1) Serial.printlnf("\n Command Alarm Value: %d", alarmStatus);
    else {Serial.printlnf("\n Error Alarm Value: %d", alarmStatus); alarmStatus==0;}
	
    return alarmStatus;
}

