package ch14_15_向上轉型範例;

class Animal {
	int num_s = 100;

	public void walk() {
		System.out.println("animal is walking.");
	}

	public void test1() {
		System.out.println("test1.......");
	}
}

class Dog extends Animal {
	int num_d = 200;

	public void walk() {
		System.out.println("Dog is walking.");
	}

	public void test2() {
		System.out.println("test2....");
	}
}

public class ch14_15 {

	public static void main(String[] args) {
		System.out.println("Upcasting..................");
		Animal animal = new Dog();// 子轉父
		animal.walk();
		animal.test1();
		System.out.println("animal.num_s");
		// animal.test2();//false
		// System.out.println("animal.num_d");

		System.out.println("Downcasting...........");

		Dog dog = (Dog) animal;
		dog.test1();
		dog.walk();
		dog.test2();
		System.out.println(dog.num_d);
		System.out.println(dog.num_s);

		// Dog d = (Dog) new Animal();false

	}

}
