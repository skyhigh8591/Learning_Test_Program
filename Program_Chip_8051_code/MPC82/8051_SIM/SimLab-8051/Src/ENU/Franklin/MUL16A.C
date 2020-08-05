//
//  A(16bit)*B(16bit) Binary unsigned view
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
unsigned int MA,MB;
unsigned long MP ;
main()
{
//  test data  0x1234*0x5678=? (0x6260060)
	MA=0x1234;
	MB=0x5678 ;
	
	F0=1 ;
	if(MB&0x1){
	    MP=MA ;
	}
	else{
	    MP=0 ;
	}
	if(MB&0x2){
	    MP= MP+((unsigned long)MA << 1) ;
	}
	if(MB&0x4){
	    MP= MP+((unsigned long)MA << 2) ;
	}
	if(MB&0x8){
	    MP= MP+((unsigned long)MA << 3) ;
	}
	if(MB&0x10){
	    MP= MP+((unsigned long)MA << 4) ;
	}
	if(MB&0x20){
	    MP= MP+((unsigned long)MA << 5) ;
	}
	if(MB&0x40){
	    MP= MP+((unsigned long)MA << 6) ;
	}
	if(MB&0x80){
	    MP= MP+((unsigned long)MA << 7) ;
	}
	if(MB&0x100){
	    MP= MP+((unsigned long)MA << 8) ;
	}
	if(MB&0x200){
	    MP= MP+((unsigned long)MA << 9) ;
	}
	if(MB&0x400){
	    MP= MP+((unsigned long)MA << 10) ;
	}
	if(MB&0x800){
	    MP= MP+((unsigned long)MA << 11) ;
	}
	if(MB&0x1000){
	    MP= MP+((unsigned long)MA << 12) ;
	}
	if(MB&0x2000){
	    MP= MP+((unsigned long)MA << 13) ;
	}
	if(MB&0x4000){
	    MP= MP+((unsigned long)MA << 14) ;
	}
	if(MB&0x8000){
	    MP= MP+((unsigned long)MA << 15) ;
	}
	F0=1 ;
	for(;;);
}
