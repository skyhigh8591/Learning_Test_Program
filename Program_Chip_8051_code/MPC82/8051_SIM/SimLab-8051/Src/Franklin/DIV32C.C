//
//  M(32bit)/N(16bit)=Q(32bit)....R(16bit)(binary unsigned view) 
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
unsigned long MM,MQ;
unsigned int MN,MR ;
main()
{
	//  ´ú¸Õ¸ê®Æ(0x12345678/0x234)=?  (0x84354....0x168) 

	MM=0x12345678;
	MN=0x234 ;
	
	F0=1 ;
	MQ=MM/MN ;
	MR=MM-MQ*MN ;
	F0=1 ;
	for(;;);
}
