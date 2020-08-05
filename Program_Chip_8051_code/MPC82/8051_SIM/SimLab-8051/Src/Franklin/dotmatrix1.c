#pragma   sm  sb cd
#include	<reg51.h>
unsigned char code dai[]= { 0xfe,0xdd,0xdb,0x0f,0xd7,0xdb,0xdd,0xfe} ;
delay()
{
	long i ;
	for(i=0;i < 100L ;i++) ;
}
main()
{
	char i ;
	char com ;
	i=0 ;
	com=0x80 ;
	for( ; ;){
	    P1=0 ;
	    P0=dai[i++] ;
	    P1=com ;
	    com >>=1 ;
	    if(i >=8){
		i=0 ;
		com=0x80 ;
	    }
	    delay() ;
	}
}
