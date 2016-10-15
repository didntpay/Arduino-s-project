/**************************************************
 * Face
 * ( 8x8 Led Dot Matrix with two 74HC595 on Arduino)
 *
 * by YFROBOT
 ***************************************************/
#define AFrame 7                        // animation array 
#define Space 4                         // Each frame space
#define FStep (8+Space)
 
//Pin connected to DS of 74HC595
int SER = 13;
//Pin connected to ST_CP of 74HC595
int RCK  = 8;
//Pin connected to SH_CP of 74HC595
int SRCK  = 12;
 
byte screen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
byte scroll = 0;
byte frame = 0;
void UpDateScreen(byte data[], unsigned long ReTime);
void ScreenDisplay( unsigned char AN[AFrame][8], int mode , unsigned long ReTime); 
unsigned char animation[AFrame][8] = {
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
  //user defined animation data
  //  {0xFF, 0xA5, 0xC3, 0x81, 0xBD, 0xA5, 0xA5, 0xFF,},
  //  {0xC3, 0xC3, 0x0, 0x18, 0x18, 0x0, 0x42, 0x3C,},
  //  {0x8, 0xC, 0xFE, 0xFF, 0xFE, 0xC, 0x8, 0x0,},
  //  {0xC3, 0x81, 0xE7, 0xE7, 0xE7, 0x81, 0x81, 0xC3,},
  {0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42,},
  {0x7E, 0x40, 0x40, 0x7C, 0x40, 0x40, 0x40, 0x7E,},
  {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C,},
  {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C,},
  {0x18, 0x24, 0x42, 0x42, 0x42, 0x42, 0x24, 0x18,},
 
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}
};
 
 
void setup() {
  pinMode(RCK, OUTPUT);
  pinMode(SRCK, OUTPUT);
  pinMode(SER, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  // Parameters 1: animation data
  // Parameters 2: display mode
  // Parameters 3: refresh time
  ScreenDisplay( animation, 0 , 200);
}
 
void UpDateScreen(byte data[], unsigned long ReTime) {
  unsigned long startime = millis();
  while (millis() - startime < ReTime)
  {
    for (int i = 0; i < 8; i++) {
      byte col = B1 << i;
      digitalWrite(RCK, LOW);
      shiftOut(SER, SRCK, LSBFIRST, ~col); //先选择列
      shiftOut(SER, SRCK, LSBFIRST, data[i]); //再送行数据
      digitalWrite(RCK, HIGH);
    }
  }
}
 
void ScreenDisplay( unsigned char AN[AFrame][8], int mode , unsigned long ReTime) {
 
  UpDateScreen(screen, ReTime);     // Refresh screen data
 
  if (mode == 0 ) {              // mode 1:refresh Display
    for (int i = 0; i < 8; i++) {
      screen[i] = AN[frame][i];
    }
    frame ++;
    if (frame >=  AFrame) {
      frame = 0;
    }
  } else if (mode == 1) {        // mode 2: scroll Display
    if (scroll > FStep * frame && scroll <= FStep * (frame + 1)) {
      for (int i = 0; i < 8; i++) {
        screen[i] = (AN[frame][i] << (scroll - FStep * frame)) | (AN[frame + 1][i] >> (FStep * (frame + 1) - scroll)) ;
      }
      if (scroll % FStep == 0) {
        frame ++;
        if (frame >=  AFrame - 1) {
          frame = 0;
          scroll = 1;
        }
      }
    }
    scroll++;
  }
}
