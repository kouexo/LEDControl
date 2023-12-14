#include "LEDControl.h"
#define USE_SERIAL Serial
// 受け取ったコマンドによってLED色を変えます。
void controlLED(String command) {
    if (command == "1") {
        turnRedOn();
    } else if (command == "2") {
        turnGreenOn();
    } else if (command == "3") {
        turnBlueOn();
    } else if (command == "4") {
        turnPurpleOn();
    } else if (command == "5") {
        animateBrightness(pixels.Color(255, 0, 0));
    } else if (command == "6") {
        animateBrightness(pixels.Color(0, 255, 0));
    } else if (command == "7") {
        animateBrightness(pixels.Color(0, 0, 255));
    } else if (command == "8") {
        animateBrightness(pixels.Color(158, 118, 180));
    } else if (command == "0") {
        turnLedOff();
    }
} 
// (0,255,255,0)のようにLEDのピンとRGBを受け取って、色を変更します。
void setCustomColor(String command) {
    int firstCommaIndex = command.indexOf(',');
    int secondCommaIndex = command.indexOf(',', firstCommaIndex + 1);
    int thirdCommaIndex = command.indexOf(',', secondCommaIndex + 1);

    int ledIndex = command.substring(0, firstCommaIndex).toInt();
    int redValue = command.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
    int greenValue = command.substring(secondCommaIndex + 1, thirdCommaIndex).toInt();
    int blueValue = command.substring(thirdCommaIndex + 1).toInt();

    pixels.setPixelColor(0, pixels.Color(redValue, greenValue, blueValue));
    pixels.show();
}

//赤
void turnRedOn() {
    pixels.setBrightness(100);
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
}
//緑
void turnGreenOn() {
    pixels.setBrightness(100);
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.show();
}
//青
void turnBlueOn() {
    pixels.setBrightness(100);
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.show();
}
//紫
void turnPurpleOn() {
    pixels.setBrightness(100);
    pixels.setPixelColor(0, pixels.Color(158, 118, 180));
    pixels.show();
}
//消灯
void turnLedOff() {
    pixels.setBrightness(100);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
}
//色明暗
void animateBrightness(uint32_t color) {
    for(int brightness = 0; brightness <= 255; brightness++){
        USE_SERIAL.println(brightness);
        pixels.setBrightness(brightness);
        pixels.setPixelColor(0, color);
        pixels.show();
        delay(10);
    }
    for(int brightness = 255; brightness >= 0; brightness--){
        USE_SERIAL.println(brightness);
        pixels.setBrightness(brightness);
        pixels.setPixelColor(0, color);
        pixels.show();
        delay(10);
    }
    pixels.setBrightness(100); // 明暗を下げた後、100に戻す。他の色が発光しないため。
}
