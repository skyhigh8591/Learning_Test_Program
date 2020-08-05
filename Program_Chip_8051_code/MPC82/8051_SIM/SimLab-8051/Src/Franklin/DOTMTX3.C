//
//  配合"4個8*8彩色點矩陣LED實習板"
//   在16*16彩色點矩陣LED上依序顯示三種顏色的中文字---"歡"
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code hwan[]= {
	0xFF,0xFF,
	0xDF,0xEF,
	0xD1,0x9F,
	0x84,0x00,
	0xD1,0x55,
	0xDE,0x55,
	0xD1,0x01,
	0x85,0x55,
	0xD1,0x55,
	0xDE,0xFE,
	0xF9,0xF9,
	0x87,0xE7,
	0xB4,0x1F,
	0xF7,0xE7,
	0xF5,0xF9,
	0xE3,0xFE,
} ;
sbit CTRLLED= P2^0 ;
sbit LRED1=P1^4 ;
sbit LGREEN1=P1^5 ;
sbit LRED2=P1^6 ;
sbit LGREEN2=P1^7 ;
#define BASEINT	25
#define INTERVAL1	BASEINT*1
#define INTERVAL2	BASEINT*2
#define INTERVAL3	BASEINT*3
main()
{
	char idx ;
	unsigned int interval ;
	unsigned char color ;
	idx=0 ;
	interval=0 ;
	color=0 ;
	for( ; ;){
	    CTRLLED=1 ;
	    if((color== 0) || (color== 2)){
 		P0=hwan[idx*2] ;
		LRED1=0 ;
		LRED1=1 ;
		P0=hwan[idx*2+1] ;
		LRED2=0 ;
		LRED2=1 ;
	    }
	    else{
		P0=0xff ;
		LRED1=0 ;
		LRED1=1 ;
		LRED2=0 ;
		LRED2=1 ;
	    }
	    if((color == 1) || (color== 2)){
 		P0=hwan[idx*2] ;
		LGREEN1=0 ;
		LGREEN1=1 ;
		P0=hwan[idx*2+1] ;
		LGREEN2=0 ;
		LGREEN2=1 ;
	    }
	    else{
		P0=0xff ;
		LGREEN1=0 ;
		LGREEN1=1 ;
		LGREEN2=0 ;
		LGREEN2=1 ;
	    }
	    P1 &=0xf0 ;
	    P1 |=idx ;
	    CTRLLED=0 ;
	    idx++ ;
	    if(idx >=16){
		interval++ ;
		idx=0 ;
	    }
	    if(interval ==  INTERVAL3){
		interval=0 ;
		color=0 ;
	    }
	    else if(interval == INTERVAL2){
		color=2 ;
	    }
	    else if(interval == INTERVAL1){
		color=1 ;
	    }
 	    Delay1ms() ;
	}
}
