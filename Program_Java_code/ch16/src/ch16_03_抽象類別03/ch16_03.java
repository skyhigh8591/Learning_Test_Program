package ch16_03_��H���O03;

abstract class Car{
	abstract void run();
	
	Car(){
		System.out.println("�����l");
	}
	void refuel() {
		System.out.println("�[�o");
	}
}

class Bmw extends Car{
	Bmw(){
		System.out.println("�����lbmw");
	}

	@Override
	void run() {
		System.out.println("�w���r�p��");
		
	}
}

public class ch16_03 {

	public static void main(String[] args) {
		Bmw bmw = new Bmw();
		bmw.refuel();
		bmw.run();

	}

}
