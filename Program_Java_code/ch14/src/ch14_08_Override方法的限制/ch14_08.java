package ch14_08_Override方法的限制;

class Animal {
	public void moving() {
		System.out.println("moving...");
	}
	public static void moving1() {
		System.out.println("moving1...");
	}
	public final void moving2() {
		System.out.println("moving2...");
	}
	
}

class Cat extends Animal {
//	protected void moving() {
//		System.out.println("Cat...");
//	}
	@Override
	public void moving() {
		System.out.println("Cat...");
	}
	
}

public class ch14_08 {

	public static void main(String[] args) {
		Animal a = new Animal();
		a.moving();
		Cat c = new Cat();
		c.moving();
		Animal.moving1();
		c.moving2();
		Cat.moving1();
		

	}

}
