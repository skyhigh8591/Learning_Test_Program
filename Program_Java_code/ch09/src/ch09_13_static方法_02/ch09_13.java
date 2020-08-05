package ch09_13_static¤èªk_02;


class Student{
	
	public int no;
	public static int Total;
	
	public static void ShowTotalStudent() {
		System.out.println("total student = " + Total);
	}
	
	public void ShowMe(String vSname) {
		System.out.println(vSname + " is #" + no );
	}
	
	public Student() {
		Total++;
		no = Total;
	}
	
	
}
public class ch09_13 {

	public static void main(String[] args) {
		Student.ShowTotalStudent();//0
		Student John = new Student();
		System.out.println("John is #" + John.no);//1
		
		Student Marry = new Student();
		Student Tom = new Student();
		
		Marry.ShowMe("Marry");
		Tom.ShowMe("Tom");
		
		Student.ShowTotalStudent();
		
		
		
		Tom.Total = 100;
		Marry.ShowTotalStudent();
		
		System.out.println(".............1............");
		Student SomeOne;
		SomeOne = Tom;
		SomeOne.ShowMe("SomeOne");
		SomeOne.no=5;
		System.out.println(Tom.no);
		System.out.println(SomeOne.no);
	}

}
