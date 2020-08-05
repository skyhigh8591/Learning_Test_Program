//******3_21.C*************************
//*功能︰結構的與右箭頭運算子範例
//****************************************
struct tag   //宣告結構變數
{
	char flag ;
	unsigned ac : 1 ;
};

  struct tag status ; // 定義變數status是結構tag的資料型態
  struct tag *sptr ;  // 宣告指標sptr為結構tag的資料型態
  
  #pragma rambank0  // 指定bit變數在RAM BANK 0
  bit vac, pac ;    // 定義 bit變數

void main()
{
  loop:
   status.flag=1 ; //flag=1
   status.flag=0 ; //flag=0
   
   status.ac=1 ;   //ac=1
   vac = status.ac ; //vac=1
   sptr = &status ;  //指標sptr指到結構status
   pac = sptr->ac ;  //pac=1   

   status.ac=0 ;   //ac=0
   vac=status.ac ; //vac=0
   pac=sptr->ac ;  //pac=0     
  goto loop;  		 
}