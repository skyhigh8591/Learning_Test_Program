package ch16_01_��H���O;

abstract class Shape{
	public void draw() {
		System.out.println("�諬");
	}	
}

class Circle extends Shape{
	public void draw() {
		System.out.println("�ꫬ");
	}	
}

public class ch16_01 {

	public static void main(String[] args) {
		Circle c = new Circle();
		c.draw();
	}
}
