//
//  配合"8*8單色點矩陣LED實習板"
//   在8*8單色點矩陣LED上顯示中文字---"大"
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code dai[]= { 0xfd,0xdb,0xd7,0x0f,0xd7,0xdb,0xdd,0xff} ;
delay3ms()
{
	Delay1ms() ;
	Delay1ms() ;
	Delay1ms() ;
}
main()
{
	unsigned char com ;
	unsigned char code *ptr =dai;


	com=0x80 ;
	for( ;;){
	    P1=0xff ;
	    P0=*ptr++ ;
	    P1=~com ;
	    com >>=1 ;
	    if(com==0){
		com=0x80 ;
		ptr= dai ;
	    }
	    delay3ms() ;
	}
}
