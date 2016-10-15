#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define uint unsigned int
#define uchar unsigned char
void tempdis(uint tempval);
void setup() {
  pinMode(13,INPUT);

}

void loop() {
  uint val,button;
  while(1)
  {
      val=analogRead(0);
      button=digitalRead(13);
      if(button=1)
      {
        delay(10);
        button=digitalRead(13);
        if(button==1)
        {
          val=val*0.48;
          tempdis(val);
          button=0;
          }
      }
      delay(2000);
    }  

}
void tempdis(uint tempval)
{
  lcd.init();
  lcd.backlight();  
  lcd.clear();
  lcd.print(tempval);
  
  }
