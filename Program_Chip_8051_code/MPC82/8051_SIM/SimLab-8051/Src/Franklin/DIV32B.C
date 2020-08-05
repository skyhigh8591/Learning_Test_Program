//
//  M(32bit)/N(16bit)=Q(32bit)....R(16bit)(binary unsigned view) 
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
unsigned long MM,MQ;
unsigned int MN,MR ;
unsigned long MT ;
main()
{
	unsigned char i ;
	//  ´ú¸Õ¸ê®Æ(0x12345678/0x234)=?  (0x84354....0x168) 

	MM=0x12345678;
	MN=0x234 ;
	
	F0=1 ;
	MT=0 ;
	for(i=0 ; i < 32 ; i++){
	    // T <=T *2 
	    MT <<= 1 ;
	    if(MM&0x80000000){
		MT++ ;
	    }
	    MM <<=1 ;

	    MQ <<=1 ;
	    if(MT >=MN){
		MT-=MN ;
		MQ++ ;
	    }
	}
	MR=MT ;
	F0=1 ;
	for(;;);
}
