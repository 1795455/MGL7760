
#define inputPin D1             // choose the input pin (for PIR sensor)
#define ledPin D7               // choose the pin for the LED

int count=0;
int alarmStatus=0;
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status