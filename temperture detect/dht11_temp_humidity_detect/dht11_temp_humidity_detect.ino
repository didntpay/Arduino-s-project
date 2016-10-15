

#include <dht11.h>
dht11 DHT11;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define uint unsigned int
#define uchar unsigned char
#define DHT11PIN A0
void setup() {
 
 lcd.init();
 lcd.backlight();
 
}

void loop() {
 
 uint check=DHT11.read(DHT11PIN);
 lcd.print("status:");
 switch (check)
 {
    case DHTLIB_OK:
    lcd.print("OK");
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    lcd.print("Checksum error"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    lcd.print("Time out error"); 
    break;
    default: 
    lcd.print("Unknown error"); 
    break;
 }
  if(check==DHTLIB_OK)
  {
      uint temp,humi;
      lcd.clear();
      lcd.print("humidity:");
      lcd.print((uint)DHT11.humidity);
      lcd.setCursor(0,1);
      lcd.print("temperture:");
      lcd.print((uint)DHT11.temperature);
      
    }
    delay(2000);
    lcd.clear();
  

}
