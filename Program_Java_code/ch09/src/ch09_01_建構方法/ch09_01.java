package ch09_01_建構方法;

class TaipeiBank
{
	int balance;
	TaipeiBank()
	{
		balance = 100;
	}
	void printBalance()
	{
		System.out.println("存款餘額" + balance);
	}
}





public class ch09_01 {

	public static void main(String[] args) {
		
		TaipeiBank A = new TaipeiBank();
		A.printBalance();
	}
}
