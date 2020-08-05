package ch16_03_抽象類別03;

abstract class Car{
	abstract void run();
	
	Car(){
		System.out.println("有車子");
	}
	void refuel() {
		System.out.println("加油");
	}
}

class Bmw extends Car{
	Bmw(){
		System.out.println("有車子bmw");
	}

	@Override
	void run() {
		System.out.println("安全駕駛中");
		
	}
}

public class ch16_03 {

	public static void main(String[] args) {
		Bmw bmw = new Bmw();
		bmw.refuel();
		bmw.run();

	}

}
