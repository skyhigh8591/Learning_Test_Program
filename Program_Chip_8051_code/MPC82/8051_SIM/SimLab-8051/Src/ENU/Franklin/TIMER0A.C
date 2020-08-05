#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
char Count ;
main()
{
	P0=Count=0 ;
	TMOD =0x10 ;
	TH0= (0xffff-10000)/256 ;
	TL0=(0xffff-10000)%256 ;
	EA=1;
	ET0=1 ;
	TR0=1 ;
	for(;;) ;
}
void timer0(void ) interrupt 1
{
	Count++ ;
	P0=Count ;
	TH0= (0xffff-10000)/256 ;
	TL0=(0xffff-10000)%256 ;
}
