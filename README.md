### saunameter - Software
Software for ESP8266 to plot temperature data to Thingspeak over Wifi.

Code should run on any ESP8266 using DS18B20 sensor.
You need to set up your own Wifi & Thingspeak settings in the configuration section of the code.

Software measures temp data on specified measuring interval (30 seconds by default) and sends results to ThingSpeak and
over serial connection for debugging purposes.

Software tries to reconnect if Wifi connection is lost. If reconnection attempts are unsuccesful it will restart ESP8266,
hopefully resolving the connection problem. Information about reconnecting will be sent over serial connection.


### saunameter - Libraries
Code was succesfully compiled with following libraries:
ThingSpeak (by MathWorks), Version 1.3.3.
DallasTemperature (by Miles Burton, Tim Newsome, Guil Barros, Rob Tillaart), Version 3.8.0
OneWire (by Jim Studt, Tom Pollard, and multiple more contributers), Version 2.3.4


### saunameter - Hardware
Folder includes 3D drawings for the casing of WeMos D1 mini. Drawings are made on SolidWorks educational edition 2017 
and are included in .sldprt and .stl formats. 

In my specific application the casing is attached to bar with zipties, so I made version of bottom of the casing with
clips for this. If you don't need clips for your application consider printing bottom half version without clips.

Case is attached by 4 * M3 screws.


## saunameter - Other notifications
For the love of god, use waterproof DS18B20 sensor. Don't be idiot and destroy the steam insulation of your sauna 
walls when installing the meter. Casing for the ESP8266 won't be waterproof, at least without using silicone to . 
I have no idea how the microcontroller will behave in hot conditions, so I wouldn't recommend installing ESP8266 
inside your sauna.
