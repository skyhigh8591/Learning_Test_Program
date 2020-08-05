package ch09_07_«Ê¸Ë_Encapsulation;

class Student{
	public String Sno;
	public String Sname;
	public int Age = 18;
	private int money = 100;
	
	public void Iam() {
		System.out.println("i am" + Sno + ":" + Sname + "3Q");
		money = 120 ;
		//System.out.println("i have" + Money  +  "dollars");
		System.out.println("i have" + Integer.toString(money)  +  " dollars");		
	}
	
}

public class ch09_07 {

	public static void main(String[] args) {
		Student S1 = new Student();
		S1.Sno = "1001";
		S1.Sname = "John";
		S1.Iam();
		//S1.Money = 500;
		System.out.println("Age=" + Integer.toString(S1.Age));
		//System.out.println("Age=" + Integer.toString(S1.Money));
	}

}
