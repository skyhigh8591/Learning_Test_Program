//******3_21.C*************************
//*单(union)絛ㄒ
//****************************************
union union_name //单跑计
{
  char num_byte ; //ノ1-byte
  int  num_int ;  //ノ2-byte
  long num_long ; //ノ4-byte
} usage;

void main()
{
  loop:
    usage.num_byte++; //单1-byte跑计患
    usage.num_int++;  //单2-byte跑计患
    usage.num_long++; //单4-byte跑计患
  goto loop;  		 
}