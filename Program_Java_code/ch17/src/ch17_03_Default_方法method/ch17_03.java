package ch17_03_Default_方法method;

interface Vehicle {
	String getBrand();

	String run();

	default String alarmOn() {
		return "開啟燈";
	}

	default String alarmOff() {
		return "關閉燈";
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
		return "安全駕駛";
	}
	
	public String alarmOff() {
		return "自己要關閉燈";
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
