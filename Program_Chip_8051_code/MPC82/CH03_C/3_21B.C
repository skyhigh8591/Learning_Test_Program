//******3_21B.C*************************
//*功能︰結構(struct)範例
//*************************************
struct str_name   //宣告結構變數
{
  unsigned flag : 1 ;    //宣告1-bit變數
  unsigned no_used : 7 ; //宣告7-bit變數
  unsigned stack : 5 ;   //宣告5-bit變數
} usage;  //結構變數名稱

void main()
{
    usage.flag=0;     
    usage.no_used=0;  
    usage.stack=0;    
  loop:
    usage.flag++;     //數值0~1
    usage.no_used++;  //數值0~0x7F(0~127)
    usage.stack++;    //數值0~0x1F(0~31)
  goto loop;  		 
}