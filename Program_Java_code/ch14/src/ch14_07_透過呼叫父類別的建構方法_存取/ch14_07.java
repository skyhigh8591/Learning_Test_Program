package ch14_07_透過呼叫父類別的建構方法_存取;

class Animal {

	private String name;

	Animal(String name) {
		this.name = name;
	}

	public void eat() {
		System.out.println(name + "正在吃的食物");
	}

	public void sleep() {
		System.out.println(name + "正在睡覺");
	}
}

class Dog extends Animal {
	Dog(String name) {
		super(name);
	}
}

public class ch14_07 {

	public static void main(String[] args) {
		Dog dog = new Dog("haly");
		dog.eat();
		dog.sleep();

	}

}
