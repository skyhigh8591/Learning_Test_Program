package ch14_06_在子類別中_利用Super關鍵字呼叫父類別的屬性_方法_建構子_02;

class Animal{
	protected String name;
	public void eat() {
		System.out.println(name + "正在吃的食物");
	}
	public void sleep() {
		System.out.println(name + "正在睡覺");
	}
}

class Dog extends Animal{
	Dog(String name)
	{
		this.name = name;
	}
}
public class ch14_06 {

	public static void main(String[] args) {
		Dog dog = new Dog("haly");
		dog.eat();
		dog.sleep();
	}

}
