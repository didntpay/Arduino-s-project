
#define uint unsigned int
#define uchar unsigned char
void setup() {
  pinMode(11,OUTPUT);
  

}

void loop() {
  uint val;
  val=analogRead(0);
  
  analogWrite(11,val/4);
  delay(3000);
  
}
