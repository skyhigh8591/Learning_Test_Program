//
//  配合"4個七段式LED(共陽)實習板"
//   連接DIPSW15~0指撥開關所代表的數值,顯示在4個七段式LED上;其掃瞄間隔為7ms
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code sstbl[]= { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e} ;
delay7ms()
{
	char i ;
	for(i=0;i < 7 ;i++){
	    Delay1ms() ;
	}
}
main()
{
	char i ;
	i=0 ;
	for( ; ;){
	    P1=0xff ;  // 關閉所有LED
	    switch(i){
		case 0:
		    P0 = sstbl[~P2 >> 4] ;
		    P1= 0xf7 ;
		    i++ ;
		    break ;
		case 1:
		    P0 = sstbl[~P2&0xf] ;
		    P1= 0xfb ;
		    i++ ;
 		    break ;
		case 2:
		    P0= sstbl[~P3 >> 4] ;
		    P1=0xfd ;
		    i++ ;
		    break ;
		case 3:
		    P0= sstbl[~P3&0xf] ;
		    P1=0xfe ;
		    i=0 ;
		    break ;
	    }
	    delay7ms() ;
	}
}
