int freq = 5000;
int ledchannel = 0;
int resolution = 8;

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
SSD1306Wire  display(0x3c, 21, 22);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

pinMode(12,INPUT);
display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  // put your main code here, to run repeatedly:
    int rd;
    rd=analogRead(12);
    Serial.println(rd);
    rd=map(rd,0,4100,0,255);
    delay(7);
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Read Value is");
    display.drawString(0,20, String(rd));
    display.display();
}
