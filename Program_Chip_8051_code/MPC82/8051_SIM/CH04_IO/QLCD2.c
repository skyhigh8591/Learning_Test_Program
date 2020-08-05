/************** QLCD2.C ***********************
*�ʧ@�G��LCD��ܨ���r
***********************************************/
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
char code  Table[]="�w��ϥ�"; //�Ĥ@��}�C�r��
void main(void)
{
  unsigned char i;        //��ƭp��
  Delay_ms(10);	 //��l��SETUP
  LCD_Cmd(0x30); //�\��]�w
  LCD_Cmd(0x02); //DDRAM�]�w��00
  LCD_Cmd(0x04);
  LCD_Cmd(0x0c); //��ܹ�ON
  LCD_Cmd(0x01); //�M���e��
  LCD_Cmd(0x80); //�]�wDDRAM��}�b�Ĥ@��
  for(i=0; i<8; i=i+2)
  {
    LCD_Data(0x01);					 
    LCD_Data(Table[i]);
    //LCD_Data(Table[i+1]);
  }
}
/***********************************************************
*��ƦW��: LCD_Data
*�\��y�z: �ǰe��ƨ��r��LCD
*��J�ѼơGdat
************************************************************/
void LCD_Data(char dat)  //�ǰe��ƨ�LCD
{
    Data=dat; //��ưe��BUS
    RS=1;RW=0;EN=1;//��Ƽg�J��LCD��
    Delay_ms(1);   //LCD���ݼg�J����
    EN=0;          //�T��LCD 
}
/***************************************************************
*��ƦW��: LCD_Cmd
*�\��y�z: �ǰe�R�O���r��LCD
*��J�ѼơGCmd
************************************************************/
void LCD_Cmd(unsigned char Cmd) //�ǰe�R�O��LCD
{
    Data=Cmd;  //�R�O�e��BUS
    RS=0;RW=0;EN=1; //�R�O�g�J��LCD��
    Delay_ms(1);    //LCD���ݼg�J����     
    EN=0;           //�T��LCD
}
