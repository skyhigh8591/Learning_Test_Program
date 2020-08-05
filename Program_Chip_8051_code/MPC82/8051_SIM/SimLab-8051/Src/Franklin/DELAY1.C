//
//   配合"F0"計算延遲時間-----8051工作頻率12Mhz
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
void delay1s() ;
void delay1ms() ;
void delay10ms() ;
void delay10ms1() ;
void delay10ms2() ;
void delay100ms() ;
main()
{
	F0=1 ;
	delay100ms() ;
	F0=1 ;
}
void delay1ms()
{
	int i ;
	char  j;
	for(i=0 ; i < 124 ;i++) ;
	j++ ;
}
void delay10ms()
{
	int i ;
	char j ;
	for(i=0 ; i < 9 ; i++){
         delay1ms() ;
	}
	for(i=0 ; i < 114;i++) ;
	j++ ;
	j++ ;
	j++ ;
	j++ ;
	j++ ;
	j++ ;
}
void delay10ms1()
{
	int i ;
	char j;
	delay1ms() ;	
	delay1ms() ;	
	delay1ms() ;	
	delay1ms() ;	
	delay1ms() ;	
	delay1ms() ;	
	delay1ms() ;	
	delay1ms() ;	
	delay1ms() ;	
	for(i=0 ; i < 124 ;i++) ;
	j++ ;
}
void delay10ms2()
{
	int i ;
	char j ;
	for(i=0 ; i < 1938 ;i++) ;
	j++ ;
	j++ ;
}
void delay100ms()
{
	long i ;
	char j ;
	for(i=0 ; i < 709 ; i++) ;  
	for(j=0 ; j < 5 ;j++) ;
	j++ ;
	j++ ;
}
void delay1s()
{
	long i ;
	char j ;
	for(i=0 ; i < 7092 ; i++) ;  //延遲時間
	for(j=0 ; j < 4 ;j++) ;
	j++ ;
	j++ ;
}
