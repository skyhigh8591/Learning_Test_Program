package ch14_06_�b�l���O��_�Q��Super����r�I�s�����O���ݩ�_��k_�غc�l_02;

class Animal{
	protected String name;
	public void eat() {
		System.out.println(name + "���b�Y������");
	}
	public void sleep() {
		System.out.println(name + "���b��ı");
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
