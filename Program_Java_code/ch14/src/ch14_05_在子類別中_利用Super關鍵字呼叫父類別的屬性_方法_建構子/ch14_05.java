package ch14_05_�b�l���O��_�Q��Super����r�I�s�����O���ݩ�_��k_�غc�l;

class Father{
	protected int x =50;
	public void printInfo() {
		System.out.println("......1......");
		System.out.println("Father...............");
		
	}
	public void printInfo1() {
		System.out.println("......4......");
	}
	
}

class Child extends Father{
	protected int x = 100;
	public void printInfo() {
		System.out.println("......2......");
		System.out.println("Child............");
		System.out.println("x");
		super.printInfo();
		printInfo1();
	}
}

public class ch14_05 {

	public static void main(String[] args) {
		Father father = new Father();
		Child child = new Child();
		father.printInfo();
		child.printInfo();
		System.out.println("......3......");
		System.out.println(child.x);
	}

}
