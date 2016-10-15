#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define uint unsigned int
#define uchar unsigned char
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0)
  {
    uint dat;
    dat=Serial.read();
    //dat=1;
    lcd.print(dat);
    //while(1);
    }

}
