//
//  配合"4*5鍵盤實習"
//   簡單鍵盤掃瞄設計
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"

void delay20ms() ;
unsigned char code IdxCol[]= {
	0 , 1 , 0 , 2 ,
	0 , 1 , 0 , 3 ,
	0 , 1 , 0 , 2 ,
	0 , 1 , 0 , 4
} ;
main()
{
	char row ;
	char keyflag ;
	char tP1 ;
	P0=0 ;
	for(;;){
	    do{
		for(P1=tP1=0xfe,row=0 ,keyflag=0 ; (row < 5);row++){
		    if((P2&0xf) != 0xf){
			keyflag=1 ;
			break ;
		    }
		    tP1 <<=1 ;
		    tP1 +=1 ;
		    P1=tP1 ;
		}
		if(keyflag== 1){
		    delay20ms() ;
		    if((P2&0xf) ==0xf){
			keyflag= 0 ;
		    }
		}
	    }
	    while(keyflag==0) ;
	    P0=row*4+IdxCol[P2&0xf];
	    do{
		while((P2&0xf) != 0xf) ;
		delay20ms() ;
	    }
	    while((P2 &  0xf) != 0xf) ;
	}
}
void delay20ms()
{
	Delay10ms();
	Delay10ms();
}
