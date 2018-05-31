### Software
Software for ESP8266 to plot temperature data to Thingspeak over Wifi.

Code should run on any ESP8266 using DS18B20 sensor.
You need to set up your own Wifi & Thingspeak settings in the configuration section of the code.

Software measures temp data on specified measuring interval (30 seconds by default) and sends results to ThingSpeak and
over serial connection for debugging purposes.

Software tries to reconnect if Wifi connection is lost. If reconnection attempts are unsuccesful it will restart ESP8266,
hopefully resolving the connection problem. Information about reconnecting will be sent over serial connection.


### Libraries
Code was succesfully compiled and tested with following libraries:

ThingSpeak (by MathWorks), Version 1.3.3

DallasTemperature (by Miles Burton, Tim Newsome, Guil Barros, Rob Tillaart), Version 3.8.0

OneWire (by Jim Studt, Tom Pollard, and multiple more contributers), Version 2.3.4

ESP8266 support to Arduino IDE was achieved by installing ESP8266 Arduino Addon. Instructions for installing the support
can be found at https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon .


### Hardware
Attach DS18B20 sensor's positive wire to +3.3V, negative wire to GND and data wire to D4 (it's called GPIO2 in software).
At least in my copy of the sensor positive wire is red, ground black, and data white, but yours may be different.

DON'T attach sensor's positive wire to +5V if you don't want to kill your ESP8266 !!!

As far as I know WeMos ESP8266 boards can't be powered by attaching 5V to 5V pin. I'm using USB cable to attach 5V to board.


### Casing
Folder includes 3D drawings for the casing of WeMos D1 mini. Drawings are made on SolidWorks Educational Edition 2017 
and are included in .sldprt and .stl formats. I've heard that non-educational editions of Solidworks may not work
with files made in Educational Edition.

In my specific application the casing is attached to bar with zipties, so I made version of bottom of the casing with
clips for this. If you don't need clips for your application consider printing bottom half version without clips.

Case is attached by 4 * M3 screws.


### Other notifications
For the love of god, use waterproof DS18B20 sensor. Don't be idiot and destroy the steam insulation of your sauna 
walls when installing the meter. Casing for the ESP8266 won't be waterproof, at least without using silicone for
sealing it. I have no idea how the microcontroller will behave in hot conditions, so I wouldn't recommend installing 
ESP8266 inside your sauna.
