package ch08_06_建立類別的物件陣列;


class TaipeiBank
{
	int account;
	int balance;
	void printinfo() {
		System.out.printf("帳戶:%d , 餘額:%d\n",account,balance);
	}
}




public class ch08_06 {

	public static void main(String[] args) {
		TaipeiBank[] shilin = new TaipeiBank[5];
		
//		shilin[0] = new TaipeiBank();
//		shilin[0].account=1;
//		shilin[0].balance=100;
//		shilin[0].printinfo();
//		
//		shilin[1] = new TaipeiBank();
//		shilin[1].account=1;
//		shilin[1].balance=100;
//		shilin[1].printinfo();
		
		for(int i=0 ; i<shilin.length ; i++)
		{
			shilin[i] = new TaipeiBank();
			shilin[i].account=100001+i;
			shilin[i].balance=100;
		}
		
		//show data
		for(int i=0 ; i<shilin.length ; i++)
		{
			shilin[i].printinfo();
		}
		
		
		System.out.println("*************************************");
		
		//show data
		for(TaipeiBank sh:shilin)
		{
			sh.printinfo();
		}

	}

}
