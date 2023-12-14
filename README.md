# LEDControl
Adafruit_NeoPixelライブラリを使用した自作関数ライブラリです。
LEDテープの値をRGBで変更できます。
LEDテープによってはRGBの配置がGRBの場合があります。
その場合は以下のコードを記載してRGB配置に変更して下さい。
コマンドをもとに使用することを想定しています。
```
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, pixelPin, NEO_GRB + NEO_KHZ800);
```
