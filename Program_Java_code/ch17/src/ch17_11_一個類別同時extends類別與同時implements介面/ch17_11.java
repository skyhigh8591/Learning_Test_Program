package ch17_11_�@�����O�P��extends���O�P�P��implements����;

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
