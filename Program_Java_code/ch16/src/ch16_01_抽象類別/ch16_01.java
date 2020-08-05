package ch16_01_抽象類別;

abstract class Shape{
	public void draw() {
		System.out.println("方型");
	}	
}

class Circle extends Shape{
	public void draw() {
		System.out.println("圓型");
	}	
}

public class ch16_01 {

	public static void main(String[] args) {
		Circle c = new Circle();
		c.draw();
	}
}
