
#define inputPin D1             // choose the input pin (for PIR sensor)
#define ledPin D7               // choose the pin for the LED
#define DHTPin D0               // choose the pin for the DHT Sensor
// Uncomment whatever type you're using!
#define DHTTYPE DHT11		// DHT 11 
//#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

int count=0;
int alarmStatus=0;
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int varStatus=0;

DHT dht(DHTPin, DHTTYPE);