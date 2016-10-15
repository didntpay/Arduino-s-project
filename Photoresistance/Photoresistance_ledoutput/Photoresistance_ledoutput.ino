

void setup() {
  pinMode(11,OUTPUT);
  
  #define uint unsigned int
  #define uchar unsigned char

}

void loop() {
  uint resistance;
  resistance=analogRead(0);
  //lcd.print(resistance);
  analogWrite(11,resistance/4);
  delay(4000);
  

}
