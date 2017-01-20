#Heart Rate Variability (HRV) Display for Arduino

Uses ILI9341 display (Library from here: https://github.com/gmtii/ili9341-arduino) and SEEED Heart Rate sensor (https://www.seeedstudio.com/Grove-Ear-clip-Heart-Rate-Sensor-p-1116.html)

Sensor connects to D2

https://www.aliexpress.com/item/3-3V-240x320-2-4-SPI-TFT-LCD-Touch-Panel-Serial-Port-Module-with-PBC-ILI9341/32627267098.html?spm=2114.01010208.3.115.HzbTpR&ws_ab_test=searchweb0_0,searchweb201602_2_10065_10068_10000032_10000025_10000029_430_10000028_10060_10062_10056_10055_10054_10059_10099_10000022_10000012_10103_10102_10000015_10096_10000018_10000019_10052_10053_10107_10050_10106_10051_10000009_10084_10083_10080_10082_10081_10110_10111_10112_10113_10114_10115_10037_10033_10032_10000041_10000044_10078_10079_10077_10000038_429_10073_10000035,searchweb201603_2,afswitch_3,single_sort_3_default&btsid=d38db430-ce03-4a31-96ba-1481a912131c
TFT display connects to:

* D4 : RESET
* D5 : CS
* D6 : D/C
* D7 : LED
* D11 : MOSI
* D12 : MISO
* D13 : SCK

If display is powered via 5v, make sure the Open Jumper on the board is soldered / connected, else the display is blank white
