#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
char buf[10] ;
char idx ;
main()
{
	idx=0 ;
	SM0=0 ;
	SM1=1 ; // Serial port in  Mode 1
	TMOD=0x20 ; // Timer1 in Mode 2
	TH1=TL1= 0xfd  ; // 0xfd:baud rate 9600/0xfa:4800
	TR1=1 ; // Enable timer
	REN=1 ;
	for(;;){
	    while(RI==0) ;
	    RI=0 ;
 	    buf[idx++]=SBUF ;
	}
}
