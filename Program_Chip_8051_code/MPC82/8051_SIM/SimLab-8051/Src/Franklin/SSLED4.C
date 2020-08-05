//
//  配合"4個七段式LED(共陽)實習板"
//    在4個七段式LED上顯示數字"1234";其掃瞄間隔為1ms
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code sstbl[]= { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90} ;
unsigned char code loc[]={ 0xf7,0xfb,0xfd,0xfe} ;
main()
{
	char i ;
	i=0 ;
	for( ; ;){
	    P1=0xff ;     //關閉共陽
	    P0=sstbl[i+1] ;
	    P1=loc[i++] ;
	    if(i >=4){
		i=0 ;
	    }
	    Delay1ms() ;
	}
}
