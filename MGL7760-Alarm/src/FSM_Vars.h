// FSM_FSM_Vars States
//-------------------------------------------------------------------------------

void FSM_Vars_OffStt_Enter();
void FSM_Vars_OffStt_Update();
void FSM_Vars_OffStt_Exit();

void FSM_Vars_OnStt_Enter();
void FSM_Vars_OnStt_Update();
void FSM_Vars_OnStt_Exit();

State FSM_Vars_OFF_STT = State(FSM_Vars_OffStt_Enter, FSM_Vars_OffStt_Update, FSM_Vars_OffStt_Exit);
State FSM_Vars_ON_STT = State(FSM_Vars_OnStt_Enter, FSM_Vars_OnStt_Update, FSM_Vars_OnStt_Exit);

FSM FSM_Vars = FSM(FSM_Vars_OFF_STT);
char FSM_Vars_CurrentStt[32];

int lastMillisVars;


void FSM_Vars_OffStt_Enter()
{
	sprintf(FSM_Vars_CurrentStt, "FSM_Vars_OFF_STT");
	Serial.println(" Enter FSM_Vars_OffStt ...");

    lastMillisVars=millis();

}

void FSM_Vars_OffStt_Update()
{
    if (varStatus == 0)
    {
        if (millis()-lastMillisVars >= 60000){Serial.println("\n Reading Vars OFF...");}

    }else{
        FSM_Vars.transitionTo(FSM_Vars_ON_STT);
    }

}
void FSM_Vars_OffStt_Exit()
{
	Serial.println(" Exit FSM_Vars_OffStt ...");
    count=0;
}

void FSM_Vars_OnStt_Enter()
{
        sprintf(FSM_Vars_CurrentStt, "FSM_Vars_On_STT");
	    Serial.println(" Enter FSM_Vars_OnStt ...");

        lastMillisVars=millis();
}

void FSM_Vars_OnStt_Update()
{

    if (millis()-lastMillisVars >= 5000){
            
            //Serial.printlnf("\n FSM_Vars On: %d", count++);lastMillis=millis();

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (its a 
            // very slow sensor)
                float h = dht.getHumidity();
            // Read temperature as Celsius
                float t = dht.getTempCelcius();
            // Read temperature as Farenheit
                float f = dht.getTempFarenheit();
            
            // Check if any reads failed and exit early (to try again).
                if (isnan(h) || isnan(t) || isnan(f)) {
                    Serial.println(" Failed to read from DHT sensor!...");
                    return;
                }

            //Serial.printlnf(" Temperature C: %0.2f  Temperature F: %0.2f    Humidity: %0.2f ", h,f,t);

            // Compute heat index
            // Must send in temp in Fahrenheit!
            
           
                float hi = dht.getHeatIndex();
                float dp = dht.getDewPoint();
                float k = dht.getTempKelvin();

                Serial.print(" Humid: "); 
                Serial.print(h);
                Serial.print(" % - ");
                Serial.print(" Temp: "); 
                Serial.print(t);
                Serial.print(" *C ");
                Serial.print(f);
                Serial.print(" *F ");
                Serial.print(k);
                Serial.print(" *K - ");
                Serial.print(" DewP: ");
                Serial.print(dp);
                Serial.print(" *C - ");
                Serial.print(" HeatI: ");
                Serial.print(hi);
                Serial.println(" *C");
                Serial.println(Time.timeStr());        

                Particle.publish("readings", String::format("{\"Hum(\%)\": %4.2f, \"Temp(°C)\": %4.2f, \"DP(°C)\": %4.2f, \"HI(°C)\": %4.2f}", h, t, dp, hi));

                lastMillisVars=millis();
    }

    if (varStatus==0){
        FSM_Vars.transitionTo(FSM_Vars_OFF_STT);
    }
}

void FSM_Vars_OnStt_Exit()
{
	Serial.println(" Exit FSM_Vars_OnStt ...");
    count=0;
}