//
//  M(32bit)/N(16bit)=Q(32bit)...R(16bit) Binary unsigned view
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
unsigned long MM,MQ;
unsigned int MN,MR ;
unsigned int MTH ;
unsigned long MTL ;
main()
{
	unsigned char i ;
	//  test data (0x12345678/0x234)=?  (0x84354....0x168)

	MM=0x12345678;
	MN=0x234 ;
	
	F0=1 ;
	MTH=MN ;
	MTL=0 ;
	for(i=0 ; i < 32 ; i++){
	    // T <=T /2 
	    MTL >>= 1 ;
	    if(MTH&0x1){
		MTL |=0x80000000 ;
	    }
	    MTH >>=1 ;
	    MQ <<=1 ;
	    if((MTH ==0) && (MM >=  MTL)){
		MQ++ ;
		MM-=MTL ;
	    }
	}
	MR=MM ;
	F0=1 ;
	for(;;);
}
