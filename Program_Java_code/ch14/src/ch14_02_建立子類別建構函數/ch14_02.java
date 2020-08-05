package ch14_02_建立子類別建構函數;


class A{
	public A() {
		System.out.println("A................");
	}
}

class B extends A{
	public B() {
		System.out.println("B................");
	}
}
public class ch14_02 {

	public static void main(String[] args) {
		B b = new B();
		
	}

}
