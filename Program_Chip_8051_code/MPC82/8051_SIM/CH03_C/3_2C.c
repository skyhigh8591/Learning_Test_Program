//*********** 3_2C.c **********************************
//*�ʧ@�G�w�qSFR�� �줸�ܼ�
//*�w��GSW1-3(P0LED)ON�A��KEY1~KEY4
//******************************************************
sfr   LED  = 0x80;   //�w�q���}P0�W��

sbit  LED0 = 0x80;   //�w�qP00���}�W��
sbit  LED1 = LED^1;  //�w�qP01���}�W��
sbit  LED2 = 0x80^2; //�w�qP02���}�W��
sbit  LED3 = 0x83;   //�w�qP03���}�W��

sbit  KEY1 = 0xB2;   //�w�qP32���}�W��
sbit  KEY2 = 0xB3;   //�w�qP32���}�W��
sbit  KEY3 = 0xEB;   //�w�qP43���}�W��(�n������L�@��)
sbit  KEY4 = 0xEA;   //�w�qP42���}�W��(�n������L�@��)
main()
{
  loop:
    LED0=KEY1;
    LED1=KEY2;
    LED2=KEY3;//(�n������L�@��)
    LED3=KEY4;//(�n������L�@��)    
  goto loop;
}