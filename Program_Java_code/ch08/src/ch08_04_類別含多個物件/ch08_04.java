package ch08_04_類別含多個物件;

class Student{
	
	public String sno;
	public String sname;
	public void Iam() {
		System.out.println("I am " + sno + ":" + sname + " 3Q");
	}
	
}


public class ch08_04 {

	public static void main(String[] args) {
		Student S1 = new Student();
		S1.sno = "1001";
		S1.sname = "John";
		S1.Iam();
		
		Student S2 = new Student();
		S2.sno = "1002";
		S2.sname = "Mary";
		S2.Iam();
		
		
		
	}

}
