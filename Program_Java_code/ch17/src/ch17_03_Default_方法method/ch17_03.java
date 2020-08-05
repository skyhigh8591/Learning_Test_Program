package ch17_03_Default_��kmethod;

interface Vehicle {
	String getBrand();

	String run();

	default String alarmOn() {
		return "�}�ҿO";
	}

	default String alarmOff() {
		return "�����O";
	}
}

class Car implements Vehicle {
	private String brand;
	
	Car(String brand) {
		this.brand = brand;
	}
	
	@Override
	public String getBrand() {
		return brand;
	}
	
	@Override
	public String run() {
		return "�w���r�p";
	}
	
	public String alarmOff() {
		return "�ۤv�n�����O";
	}
}

public class ch17_03 {
	public static void main(String[] args) {
		Car C = new Car("Toyota");
		System.out.println(C.getBrand());
		System.out.println(C.run());
		System.out.println(C.alarmOff());
		System.out.println(C.alarmOn());
	}
}
