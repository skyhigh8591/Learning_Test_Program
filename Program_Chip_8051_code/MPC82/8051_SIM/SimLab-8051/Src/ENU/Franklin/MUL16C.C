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
	MP=(unsigned long)MA*(unsigned long)MB ;
	F0=1 ;
	for(;;);
}
