#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  #define uint unsigned int
  #define uchar unsigned char

}

void loop() {
  uint temp,val;
  temp=analogRead(0);
  temp=temp*0.48;
  if(val%temp>5)
  {
      temp=temp+1;//? don't know what for.
  }
  lcd.print(temp);
  delay(5000);
  lcd.clear(); 
}
