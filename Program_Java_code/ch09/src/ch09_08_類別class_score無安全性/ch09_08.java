package ch09_08_���Oclass_score�L�w����;

class Student {
	public String Sno;
	public String Sname;
	public int Score;

	public void Iam() {
		System.out.println("I am " + Sno + ":" + Sname + " score=" + Integer.toString(Score));
	}
}

public class ch09_08 {
	
	public static void main(String[] args) {
		Student S1 = new Student();
		S1.Sno = "1001";
		S1.Sname = "JOHN";
		S1.Score = 500; // ?? too big Max=100�A�L�k�]�W�h
		S1.Iam(); // 500
	}
}
