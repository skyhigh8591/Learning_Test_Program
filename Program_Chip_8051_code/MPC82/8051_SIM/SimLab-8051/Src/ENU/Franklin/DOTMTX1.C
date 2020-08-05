//
//  配合"8*8單色點矩陣LED實習板"
//   在8*8單色點矩陣LED上顯示中文字---"大"
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
unsigned char code dai[]= { 0xfd,0xdb,0xd7,0x0f,0xd7,0xdb,0xdd,0xff} ;
void delay1ms()
{
	int i ;
	char  j;
	for(i=0 ; i < 124 ;i++) ;
	j++ ;
}
delay3ms()
{
	delay1ms() ;
	delay1ms() ;
	delay1ms() ;
}
main()
{
	unsigned char com ,idx;

	com=0x80 ;
	idx=0 ;
	for( ;;){
	    P1=0xff ;
	    P0=dai[idx++] ;
	    P1=~com ;
	    com >>=1 ;
	    if(idx==8){
		idx=0;
		com=0x80 ;
	    }
	    delay3ms() ;
	}
}
