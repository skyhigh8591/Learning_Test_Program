//
//   P0.0~P0.7 and P1.0~P1.3 control 4 pieces of Seven-Segment LED,
//   P2.0 select timer mode/counter mode;ON is timer mode, OFF is counter mode
//   P2.1 to start/stop timer/counter ;On is to start timer/counter , OFF is to stop timer/counter
//   P2.2 is counter pulse input
//
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>

unsigned char code sstbl[]={
	0xc0,0xf9,0xa4,0xb0,
	0x99,0x92,0x82,0xf8,
	0x80,0x90,0x88,0x83,
	0xc6,0xa1,0x86,0x8e
} ;
void delay1ms()
{
	int i ;
	char  j;
	for(i=0 ; i < 124 ;i++) ;
	j++ ;
}

char Count=0;

main()
{
	char Lt=1, Time=1;
	char i, s=0, ch[4]={0,0,0,0};

	TMOD =0x01;
	TH0= (0xffff-50000)/256 ;
	TL0= (0xffff-50000)%256 ;
	EA=1;
	ET0=1 ;
	TR0=1 ;

	for(i=0; ;i++){
	   if(~P2&0x02 ){
		if(~P2&0x01 ){ // timer mode
		    if(Time == 0){
			Time=1;
			ch[0]=0;
			ch[1]=0;
			ch[2]=0;
			ch[3]=0;
			s = 0;
			Count = 0;
		    }
		    if(Count>=20){
			Count -= 20;
			s++;
			if( s>=60 ){
			    s=0;
			    ch[3]++;
			    if(ch[3]>9){
				ch[3]=0;
				ch[2]++;
				if(ch[2]>=6){
				    ch[2]=0;
				    ch[1]++;
				    if(ch[1]>9){
					ch[1]=0;
					ch[0]++;
					if(ch[0]>9){
					    ch[0]=0;
					}
				    }	
				}
			    }
			}
		    }
		}
		else{          // counter mode
		    if(Time == 1){
			Time=0;
			ch[0]=0;
			ch[1]=0;
			ch[2]=0;
			ch[3]=0;
			s = 0;
		    }
		    if( Lt==1 ){
			if((~P2&0x04)==0 ){
			    Lt=0;
			    ch[3]++;
			    if( ch[3]>9 ){
				ch[3]=0;
				ch[2]++;
				if(ch[2]>9){
				    ch[2]=0;
				    ch[1]++;
				    if(ch[1]>9){
					ch[1]=0;
					ch[0]++;
					if(ch[0]>9){
					    ch[0]=0;
					}
				    }
				}
			    }
			}
		    }
		    else{
			if(~P2&0x04){
			    Lt=1;
			}
		    }
		}
	    }
  	    i &= 3;	
	    P1=0xff ;  // OFF all LED
	    P0 = sstbl[ch[i]];
	    if(s&1) P0&=0x7f;
	    else    P0|=0x80;		
	    P1 = ~(1<<i);
	    delay1ms();
	}
}

void timer0(void ) interrupt 1
{
	Count++;
	TH0= (0xffff-50000)/256 ;
	TL0=(0xffff-50000)%256 ;

}
