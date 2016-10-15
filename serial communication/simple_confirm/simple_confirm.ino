void setup() {
  Serial.begin(9600);
  Serial.print("prees a to confirm");
  #define uint unsigned int
  #define uchar unsigned char
}

void loop() {
  uint dat;
  dat=Serial.available();
  if(dat>0)
  {
    uchar dat1;
    dat1=Serial.read();
    Serial.print(dat1);
    Serial.end();
    /*if(dat=1)
    {
      Serial.print("change your baud to 300 ");
      Serial.begin(300);
    }*/
  }

}
