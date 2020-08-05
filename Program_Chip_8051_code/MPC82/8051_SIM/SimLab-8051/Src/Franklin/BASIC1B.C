//
// 兩個8位元數的相加
//
#pragma oe db pw(80) SM SB CD
unsigned char data *val1;
unsigned char data *val2;
unsigned char data *res;
main()
{
	val1= 0x40 ;
	val2= 0x41 ;
	res= 0x42 ;
	*res=*val1+*val2 ;
	for(;;);
}
