package ch17_11_一個類別同時extends類別與同時implements介面;

interface Dog{
	void running();
}

class Horse{
	public void who() {
		System.out.println("i am horse");
	}
}

class Pet extends Horse implements Dog{
	@Override
	public void running() {
		System.out.println("Per is running");	
	}
}

public class ch17_11 {

	public static void main(String[] args) {
		Pet obj = new Pet();
		obj.running();
		obj.who();

	}

}
