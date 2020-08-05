//
//  A(16bit)*B(16bit) Binary unsigned view
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
unsigned int MA,MB;
unsigned long MP ;
main()
{
	unsigned int AL,AH,BL,BH ;
	unsigned int ALBL,AHBL,ALBH,AHBH ;
//  test data  0x1234*0x5678=? (0x6260060)
	MA=0x1234;
	MB=0x5678 ;
	F0=1 ;
	AL=MA&0xff ;
	AH=MA >> 8 ;
	BL=MB&0xff ;
	BH=MB >> 8 ;
	ALBL=AL*BL ;
	AHBL=AH*BL ;
	ALBH=AL*BH ;
	AHBH=AH*BH ;
	MP=(unsigned long)(ALBL)+((unsigned long)(AHBL) << 8)+((unsigned long)(ALBH) << 8)+((unsigned long)(AHBH) << 16) ;
	F0=1 ;
	for(;;);
}
