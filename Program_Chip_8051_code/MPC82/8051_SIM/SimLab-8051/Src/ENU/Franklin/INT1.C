#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
char Shift ;
main()
{
	P0=Shift=1 ;
	IT1=1 ; // Detect negative edge trigger 	
	EA=1;
	EX1=1 ;
	for(;;) ;
}
void external1(void ) interrupt 2
{
	Shift <<=1 ;
	if(Shift == 0){
	    Shift=1 ;
	}
	P0=Shift;
}
