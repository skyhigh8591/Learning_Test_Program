//
//
//   Display Chinese word "da" (three color) on 8*8 Color Dot-matrix LED
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code dai[]= { 0xfd,0xdb,0xd7,0x0f,0xd7,0xdb,0xdd,0xff} ;
#define BASEINT	25
#define INTERVAL1	BASEINT*1
#define INTERVAL2	BASEINT*2
#define INTERVAL3	BASEINT*3
delay3ms()
{
	Delay1ms() ;
	Delay1ms() ;
	Delay1ms() ;
}
main()
{
	char idx ;
	unsigned char com ;
	unsigned int interval ;
	unsigned char color ;
	idx=0 ;
	com=0x80 ;
	interval=0 ;
	color=0 ;
	for( ; ;){
	    P1=0xff ;
	    if((color== 0) || (color== 2)){
 		P0=dai[idx] ;
	    }
	    else{
		P0=0xff ;
	    }
	    if((color == 1) || (color== 2)){
		P2=dai[idx] ;
	    }
	    else{
		P2=0xff ;
	    }
	    idx++ ;
	    P1=~com ;
	    com >>=1 ;
	    if(idx >=8){
		interval++ ;
		idx=0 ;
		com=0x80 ;
	    }
	    if(interval ==  INTERVAL1){
		color=1 ;
	    }
	    else if(interval == INTERVAL2){
		color=2 ;
	    }
	    else if(interval == INTERVAL3){
		interval=0 ;
		color=0 ;
	    }
	    delay3ms() ;
	}
}
