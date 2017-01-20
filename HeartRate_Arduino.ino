#include "RunningAverage.h"
#include "Streaming.h"
#include <stdint.h>
#include "TFTv2.h"
#include <SPI.h>

#define THRESHOLD 150
#define MAXCONV 240
#define PULSEMIN 40
#define PULSEMAX 170
#define PSIZE 4

RunningAverage heartRaate(20);
unsigned long lastBeat = 0;
int y = 0;
int lastY=-1, lastX=-1;

void setup(){
    Serial.begin(115200L);
    TFT_BL_ON;      // turn on the background light
    Tft.TFTinit();  // init TFT library
    Serial.println("Heart rate variation display begin.");
    attachInterrupt(0, interrupt, RISING);//set interrupt 0,digital port 2
}
void loop() {
  if (y >= 320) {
    Tft.fillScreen();
    y = 0;
  }
}

void interrupt() {
  if (lastBeat != 0) {
    unsigned long sub = millis() - lastBeat;
    lastBeat = millis();
    double instHR = (double)60000.00/sub;
    if (instHR > PULSEMAX || instHR < PULSEMIN) return;  
    heartRaate.addValue(instHR);
    Serial << "avg: " << heartRaate.getAverage() << ", inst:" << instHR << " - " ;
    int a = heartRaate.getAverage() * 10;
    int x = map ((int)(instHR*10), a - THRESHOLD, a + THRESHOLD, 0, MAXCONV);
    //Serial << "x= " << x;
    //  for (int i=0; i<x; i++) Serial << "#";
    Tft.fillCircle(x,320- y, PSIZE/2,YELLOW);
    if (lastX > 0 && y > 0) Tft.drawLine(lastX, 320-lastY, x, 320-y, GRAY1);
    String s = String("AvgHR: ") + (int)heartRaate.getAverage() + "  InstHR: " + (int)instHR;
    //Tft.fillRectangle(200, 320 - 100,40, 100, BLACK);
    //Tft.drawString((char*)s.c_str(), 200, 320 - 100, 3, GREEN);
    lastX = x;
    lastY = y;    
    Serial << endl;
    y += PSIZE;
  } else {
    lastBeat = millis();
  }
}

