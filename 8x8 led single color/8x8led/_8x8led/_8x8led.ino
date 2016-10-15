//this program requires a library from http://yfrobot.com/forum.php?mod=viewthread&tid=11735&highlight=74hc595
#define uint unsigned int
#define uchar unsigned char
#define aframe 6
#define ser 13
#define clk 12
#define latchpin 8
uint table1[aframe][8]={
0x0,0x24,0x24,0x3C,0x24,0x24,0x0,0x0,
0x0,0x0,0x3C,0x20,0x38,0x20,0x3C,0x0,
0x0,0x20,0x20,0x20,0x20,0x3C,0x0,0x0,
0x0,0x20,0x20,0x20,0x20,0x3C,0x0,0x0,
0x0,0x0,0x18,0x24,0x24,0x24,0x18,0x0
};//customized shape on led

void updatescreen(uint datable[8],uint retime);
void screendisplay(uint table2[aframe][8],uint mode,uint retime);
void setup() {
  pinMode(ser,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(latchpin,OUTPUT);

}

void loop() 
{
  screendisplay(table1,0,300);
  

}
void updatescreen(uint datable[8],uint retime)
{
  uint starttime;
  starttime=millis();
  while(millis()-starttime<retime)//frequency=retime
  {
    for(uint i=0;i<8;i++)
    {
      uchar col=B1<<i;
      digitalWrite(latchpin,LOW);
      shiftOut(ser,clk,LSBFIRST,~col);
      shiftOut(ser,clk,LSBFIRST,datable[i]);
      digitalWrite(latchpin,HIGH);
    }
  }
}

void screendisplay(uint table2[aframe][8],uint mode,uint retime)
{ 
   uint screen[8]={0};
   uint col,row;
   
   if(mode==0)//refresh display
   {
      while(row<aframe)
      {
        updatescreen(screen,retime);
        for(col=0;col<8;col++)
        {
          screen[col]=table2[row][col];
        }
        row++;
      }
        
    }
    else if(mode==1)//scroll display
    {
      uint scroll,space,frame;
      space=4;
      frame=8+space;
      while(row!=aframe)
      {
        updatescreen(screen,retime);
        for(col=0;col<8;col++)
        {
          screen[col]=(table2[row][col]<<scroll|table2[row+1][col]>>(frame-scroll));//|data to achieve scroll display by combining every line's data with next line.
        }
        scroll++;
        if(scroll%frame==0)
        {
          scroll=0;
          row++;
        }
      }
      
    }
}
