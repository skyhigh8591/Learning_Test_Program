package ch14_12_���h�~��;

class Animal{
	protected String name;
	public void eat() {
		System.out.println(name + "���b�Y");
	}
	public void sleep() {
		System.out.println(name + "���b��");
	}
}

class Dog extends Animal{
	Dog(String name){
		this.name = name;
	}
	public void barking() {
		System.out.println(name+"���b�s");
	}
}
class Bird extends Animal{
	Bird(String name){
		this.name = name;
	}
	public void flying() {
		System.out.println(name+"���b��");
	}
	
}

public class ch14_12 {

	public static void main(String[] args) {
		Dog d = new Dog("haly");
		d.eat();
		d.sleep();
		d.barking();
		
		Bird b = new Bird("tony");
		b.eat();
		b.sleep();
		b.flying();


	}

}
