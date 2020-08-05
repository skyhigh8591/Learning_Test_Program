// PROGRAM	: U2_1_2.c							2017.0420
// FUNCTION	: Nest Interrupt Demo Program		By Steven
#include <HT66F2390.h>			
#include "MyType.H"
#define	LEDPort		_pf							//DEFINE LED PORT
#define	LEDPortC	_pfc						//DEFINE LED CONTROL REG.
#define	SEGPort		_pg							//DEFINE 7-SEG PORT
#define	SEGPortC	_pgc						//DEFINE 7-SEG PORT CONTROL REG.			
const u8 SEG_TAB[] = {							//7-Segment Table
			0x3F,0x06,0x5B,0x4F,0x66,
			0x6D,0x7D,0x07,0x7F,0x67};
void Delayms(u16);
void main()
{	u8 i;
	_wdtc=0b10101111;							//�����ݭ̪��p�ɾ�
	LEDPort=0xFF; LEDPortC=0;					//�W��LEDPort����X�ݩʨÿ�XFFh����LEDs
	SEGPort=0; SEGPortC=0;						//�W��SEGPort����X�ݩʨÿ�X00h�����C�q��ܾ�
	_papu1=1; _papu7=1;							//�P��PA3/PA7 Pull-High�q��
	_int1ps=1;									//���wINT1�\���PA7�}���{
	_integ=0b00001010;							//���INT1/INT0���t�tĲ�o����
	_int0e=1; _int1e=1; _emi=1;					//�P��INT0,INT1�Τ��_�`�}��
	while(1)
	{	for(i=0;i<10;i++)						//��ܰj�� 
		{	SEGPort=SEG_TAB[i];					//�d��ðe����ܾ����	
		 	Delayms(1000);						//����1Sec
		}
	}
}
DEFINE_ISR(ISR_Int0,0x04)						//INT0 ISR
{	u8 i,temp;
	_int0e=0;									//�T��INT1���_,�קK�u���޵o���~�ʧ@
	_emi=1;										//�P�त�_�`�}��
	temp=LEDPort;								//�O�dLEDPort�ثe���A	
	LEDPort=0b11111110;							//�]�wLEDPort���
	for(i=0;i<8;i++)
	{	GCC_DELAY(250000); GCC_DELAY(250000);   //����0.25Sec
		GCC_RL(LEDPort);	 		           	//LEDPort����
	}
	LEDPort=temp;								//�٭�LED_Port�����A
	_int0f=0;									//�קK�u���޵o���~�ʧ@
	_int0e=1;									//���s�P��INT0���_
}
DEFINE_ISR(ISR_Int1,0x08)						//INT1 ISR
{	u8 i,temp;
	_int1e=0;									//�T��INT1���_,�קK�u���޵o���~�ʧ@
	_emi=1;										//�P�त�_�`�}��
	temp=LEDPort;								//�O�dLEDPort�ثe���A
	LEDPort=0b01111111;							//�]�wLEDPort���
	for(i=0;i<8;i++)
	{	GCC_DELAY(250000); GCC_DELAY(250000);	//����0.25Sec
		GCC_RR(LEDPort);;						//LED_Port�k��
	}
	LEDPort=temp;								//�٭�LEDPort�����A
	_int1f=0;									//�קK�u���޵o���~�ʧ@
	_int1e=1;									//���s�P��INT1���_
}
void Delayms(u16 del)
{	u16 i;										//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}