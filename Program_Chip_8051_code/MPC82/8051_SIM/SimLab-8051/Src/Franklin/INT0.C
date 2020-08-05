#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
char Count ;
main()
{
	P0=Count=0 ;
	IT0=1 ; // °»´ú­t½tÄ²µo°Ê§@
	EA=1;
	EX0=1 ;
	for(;;) ;
}
void external0(void ) interrupt 0
{
	Count++ ;
	P0=Count ;
}
