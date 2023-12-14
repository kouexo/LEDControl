#ifndef LEDControl_h
#define LEDControl_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

extern Adafruit_NeoPixel pixels;

void controlLED(String command);
void setCustomColor(String command);
void turnRedOn();
void turnGreenOn();
void turnBlueOn();
void turnPurpleOn();
void turnLedOff();
void animateBrightness(uint32_t color);

#endif
