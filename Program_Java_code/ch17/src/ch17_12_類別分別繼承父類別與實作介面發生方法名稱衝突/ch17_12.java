package ch17_12_類別分別繼承父類別與實作介面發生方法名稱衝突;

interface Dog{
	void who();
	default void running() {
		System.out.println("dog is running");
	}
}

interface Cat{
	void who();
	default void running() {
		System.out.println("Cat is running");
	}
}

class Horse{

	public void running() {
		System.out.println("Horse is running");
	}
}

class Pet extends Horse implements Dog, Cat{

	@Override
	public void who() {
		System.out.println("I am pet");
		
	}
	
}
public class ch17_12 {

	public static void main(String[] args) {
		Pet obj = new Pet();
		obj.running();
		obj.who();

	}

}
