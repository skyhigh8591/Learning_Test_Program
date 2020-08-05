package ch17_13_介面的多層次繼承中發生default方法名稱相同;

interface Aniaml{
		void who();
		default void running(){
			System.out.println("Aniaml is running");
		}
	
}

interface Dog extends Aniaml{
	default void running() {
		System.out.println("Dog is running");
	}
}

class Pet implements Dog{

	@Override
	public void who() {
		System.out.println("i am pet");
		
	}
	
	
}

public class ch17_13 {

	public static void main(String[] args) {
		Pet obj = new Pet();
		obj.running();
		obj.who();

	}

}
