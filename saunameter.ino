/*  Sauna temperature monitor v1.0.1 for ESP8266 using DS18B20
 *
 *  Measures temperature with DS18B20 sensor and pushes data to ThingSpeak.
 *  Connect DS18B20's positive pin to +3.3V, negative to GND and data to D4 (GPIO2).
 *
 *  Configuration section is in the beginning, set it up before uploading code to ESP8266! :)
 *
 *  Tested on LoLin NodeMCU v3 & WeMos D1 mini.
 *
 *  Written by Antti Kallunki
 */

#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ******************************** Configuration  ********************************
// Thingspeak: 
const char* writeAPI = "WRITE API HERE";      // Channel Write API key
unsigned long channelID = 000000;             // Channel ID, 6 digit number
const int dataField = 1;                      // Number of field to which write temperatures to
// Wifi
const char* ssid = "MY NETWORK SSID";         // Your network SSID
const char* password = "MY_PASSWORD";         // Your network password
// Other configuration
int measuringInterval = 30000;                // has to be >15000 milliseconds due to ThingSpeak
int sensorPin = 2;                            // 2 is D4 on board
// ***************************** End of configuration *****************************

// Declaring functions
// Sends temperature data over serial
void SerialPrintTemp(float temp);
// Reconnects to wifi. Returns true if reconnect is succesful, false if not.
// Parameter maxTime is the maimum time spent trying to reconnect in milliseconds
bool ReconnectToWifi(unsigned int maxTime);

// Setting up Wifi Client
WiFiClient client;
// Setting up OneWire
OneWire oneWire(sensorPin);
// Passing reference to Dallas Temperature
DallasTemperature sensors(&oneWire);

void setup() {
    Serial.begin(115200);
    delay(15);

    WiFi.begin(ssid, password);
    Serial.print("Connecting to network: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nBeep boop, connected!");
    Serial.println("IP-address: ");
    Serial.println(WiFi.localIP());

    ThingSpeak.begin(client);
    Serial.println("Connecting to ThingSpeak");
    sensors.begin();
    Serial.println("Starting sensing!");
}

void loop()
{
    // Setting up variables
    float temp = 0;
    unsigned long measuringTimer = 0;

    // Loop to run measurements and push data to cloud
    while(1)
    {
        // Resetting watchdog timer, is required since loop has no delay/yield otherwise
        yield();

        // Measures temperature and pushes data when set measuring interval has passed
        if (millis() - measuringTimer >= measuringInterval)
        {
            // Reading temperature in celsius from first sensor on bus (Index = 0)
            sensors.requestTemperatures();
            temp = sensors.getTempCByIndex(0);

            // Reporting results over serial
            SerialPrintTemp(temp);

            // Reconnecting if connection is lost
            if(WiFi.status() != WL_CONNECTED)
            {
                // Attemps reconnecting for 15 seconds, if unsuccesful, restarts device
                if(!ReconnectToWifi(15000) )
                {
                    ESP.restart();
                }
            }

            // Pushing data to ThingSpeak
            ThingSpeak.setField(dataField, temp);
            ThingSpeak.writeFields(channelID, writeAPI);

            // Resetting timer
            measuringTimer = millis();
        }
    }
}

void SerialPrintTemp(float temp)
{
    Serial.print("\nTemperature: ");
    Serial.print(temp);
    Serial.print(" *C");
}

bool ReconnectToWifi(unsigned int maxTime)
{
    Serial.print("\nConnection lost, reconnecting.\n");
    WiFi.reconnect();

    unsigned long reconnectTimer = millis();
    unsigned long dotPrintTimer = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        yield();

        // Prints dot over serial every 0.5 seconds
        if(millis() - dotPrintTimer > 500)
        {
            Serial.print(".");
            dotPrintTimer = millis();
        }

        // Returns false if maxTime is exceeded
        if(millis() - reconnectTimer > maxTime)
        {
            Serial.print("\nReconnecting failed.");
            return false;
        }
    }
    Serial.print("\nReconnected succesfully!");
    return true;
}
