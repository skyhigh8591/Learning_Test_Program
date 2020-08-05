// PROGRAM	: U4Ext_02.c									2020.0320
// FUNCTION	: PTM2 Compare Match Output Mode Control  		By Steven
// NOTE		: Code Example for Palying Songs Application
#include <HT66F2390.h>
#include "MyType.H"
#define fSYS   8000000										//8MHz System Frequency
const u8  BEE[] ={
			(5<<4)+3,(3<<4)+3,(0<<4)+1,(3<<4)+5,			//Song Table Hi-nibble:Pitch, Lo-nibble:Duration
			(4<<4)+3,(2<<4)+3,(0<<4)+1,(2<<4)+5,
			(1<<4)+3,(2<<4)+3,(3<<4)+3,(4<<4)+3,
			(5<<4)+2,(0<<4)+1,(5<<4)+2,(0<<4)+1,
			(5<<4)+5,
			0};
const u8  TIGER[] ={
			(1<<4)+4,(2<<4)+4,(3<<4)+4,(1<<4)+4,(0<<4)+1,	//Song Table Hi-nibble:Pitch, Lo-nibble:Duration
			(1<<4)+4,(2<<4)+4,(3<<4)+4,(1<<4)+4,
			(3<<4)+4,(4<<4)+4,(5<<4)+6,(0<<4)+1,
			(3<<4)+4,(4<<4)+4,(5<<4)+6,
			0};				  
const u16 Pitch_TAB[] = {			      					//Pitch Control Table
			fSYS/(523*2*4),fSYS/(587*2*4),fSYS/(659*2*4),
			fSYS/(698*2*4),fSYS/(785*2*4),fSYS/(880*2*4),
			fSYS/(998*2*4),fSYS/(523*4*4),fSYS/(587*4*4),
			fSYS/(659*4*4),fSYS/(698*4*4),fSYS/(785*4*4),
			fSYS/(880*4*4),fSYS/(998*4*4),fSYS/(523*8*4),
			fSYS/(587*8*4)};
void PlaySong(const u8 *ptr);
void Delayms(u16);
void Delay500ms(u8);
u8 ScanKey(void);
void main()
{	_wdtc=0b10101111;										//關閉看們狗計時器
	_ptm2c0=0; _ptm2c1=0b00110001;							//PTM2:比對吻合輸出模式,CCRA吻合清除***
	_pds0=0x10;												//設定PD2為PTP2功能***	
	_sledc1=0x30;											//設置PD[3:0]源流為Level 3***	
	while(1)
	{	PlaySong(BEE);
		Delayms(1000);
		PlaySong(TIGER);
		Delayms(1000);	
	}
}
void PlaySong(const u8 *ptr)
{	u8 Pitch;
	while(*ptr!=0)
	{	if((*ptr & 0xF0)!=0)
		{	Pitch=(*ptr>>4)-1;
		_ptm2al=(u8)Pitch_TAB[Pitch];		         		//取得計數時間常數
		_ptm2ah=Pitch_TAB[Pitch]>>8;          
		_pt2on=1;											//啟動PTM2計數
		}
		Delay500ms(*ptr & 0x0F); _pt2on=0;
		ptr++;
	}
}
void Delay500ms(u8 i)
{	u16 j;
	for(j=0;j<i;j++) GCC_DELAY(100000);					//Delay i*500ms
}
void Delayms(u16 i)
{	u16 j;
	for(j=0;j<i;j++) GCC_DELAY(2000);					//Delay i*1ms
}	