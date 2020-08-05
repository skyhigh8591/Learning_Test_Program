//
// 兩個8位元數的相加
//
#pragma oe db pw(80) SM SB CD
unsigned char data *val1;
main()
{
	val1= 0x40 ;
	*(val1+2)=*val1+*(val1+1) ;
	for(;;);
}
