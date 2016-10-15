#include <LiquidCrystal_I2C.h>

#include <Wire.h>

void setup() {


  Serial.begin(9600);
  #define uint unsigned int
  #define uchar unsigned char

}

void loop() {
  Serial.write("hhh");
  while(1);

}
