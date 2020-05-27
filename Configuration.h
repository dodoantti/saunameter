// --- Thingspeak
#define THINGSPEAK_KEY "WRITE API HERE";  // Channel Write API key
#define THINGSPEAK_ID 000000;             // Channel ID
#define THINGSPEAK_DATAFIELD 1;           // Number of field to which write temperatures to

// --- Wifi
#define WIFI_SSID "MY NETWORK SSID";      // Your network SSID
#define WIFI_PASSWORD "MY_PASSWORD";      // Your network password

// --- Sensor configuration
// SENSOR_TYPE 1 = DS18B20
#define SENSOR_TYPE 1
#define SENSOR_PIN 2                      // 2 is D4 on board

// --- Other configuration
#define MEASURING_INTERVAL 30000          // In milliseconds,  has to be >15000 ms due to ThingSpeak
