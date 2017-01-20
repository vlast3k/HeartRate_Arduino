#Heart Rate Variability (HRV) Display for Arduino

Uses ILI9341 display (Library from here: https://github.com/gmtii/ili9341-arduino) and SEEED Heart Rate sensor (https://www.seeedstudio.com/Grove-Ear-clip-Heart-Rate-Sensor-p-1116.html)

Sensor connects to D2

TFT display connects to:

* D4 : RESET
* D5 : CS
* D6 : D/C
* D7 : LED
* D11 : MOSI
* D12 : MISO
* D13 : SCK

If display is powered via 5v, make sure the Open Jumper on the board is soldered / connected, else the display is blank white
