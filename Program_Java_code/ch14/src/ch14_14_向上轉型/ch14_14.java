package ch14_14_�V�W�૬;

class School{
	int num_s = 100;
	public void demo() {
		System.out.println("school");
	}
	public void test1() {
		System.out.println("test1");
	}
	public void test2() {
		System.out.println("test2");
	}
	
}

class Departement extends School{
	int num_D=200;
	public void demo() {
		System.out.println("Departement");
	}
	public void test3() {
		System.out.println("test3");
	}
}

public class ch14_14 {

	public static void main(String[] args) {
		System.out.println("new School ��.........");
		School A = new School();
		A.demo();
		A.test1();
		A.test2();
		System.out.println(A.num_s);
		
		System.out.println("new School �l.........");
		
		Departement B = new Departement();
		B.demo();
		B.test1();
		B.test2();
		B.test3();
		System.out.println(B.num_s);
		System.out.println(B.num_D);
		
		System.out.println("upcasting.........");
		
		//�Ĥ@��
		School C = new Departement();
		
		//�ĤG��
		C.demo();
		C.test1();
		C.test2();
		
		//C.test3(); false
		System.out.println(C.num_s);
		
		//System.out.println(C.num_D); false
		
		
		
	}

}
