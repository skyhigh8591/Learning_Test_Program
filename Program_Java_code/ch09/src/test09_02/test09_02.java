package test09_02;

import java.util.Scanner;

class CBox {

	private  double length = 100;
	private  double width = 50;
	private  double height = 80;

	public  double getLength() {
		return length;
	}

	public   void setLength(double length) {
		this.length = length;
	}

	public  double getWidth() {
		return width;
	}

	public   void setWidth(double width) {
		this.width = width;
	}

	public   double getHeight() {
		return height;
	}

	public   void setHeight(double height) {
		this.height = height;
	}

	public  void setValues(double num1, double num2) {
		this.length = num1;
		this.width = num2;
	}

	public void setValues(double num1, double num2, double num3) {
		this.length = num1;
		this.width = num2;
		this.height = num3;
	}


	double volume() {
		return getHeight() * getWidth() * getLength();
	}

	double surfaceArea() {
		return getLength() * getWidth();
	}

	void showData() {
		System.out.printf("length=%.2f width=%.2f height=%.2f\n", getLength(), getWidth(), getHeight());
	}

	void showAll() {
		System.out.printf("體積=%.2f\n", volume());
		System.out.printf("面積=%.2f\n", surfaceArea());
		showData();
	}
}



public class test09_02 {

	public static void main(String[] args) {
		CBox box = new CBox();
		box.setLength(100);
		box.setWidth(50);
		box.setHeight(80);
		System.out.println("長 " + box.getLength());
		System.out.println("寬 " + box.getWidth());
		System.out.println("高 " + box.getHeight());
		System.out.println("..................................");
		System.out.printf("體積%.2f\n", box.volume());
		System.out.println("..................................");
		System.out.printf("面積%.2f\n", box.surfaceArea());
		System.out.println("..................................");
		box.showData();
		System.out.println("..................................");
		box.showAll();
		System.out.println("..................................");

		Scanner scanner = new Scanner(System.in);
		System.out.print("輸入 length");
		double o = scanner.nextDouble(); // 讀取輸入數字
		Scanner scanner2 = new Scanner(System.in);
		System.out.print("輸入 width");
		double p = scanner2.nextDouble(); // 讀取輸入數字
		box.setValues(o, p);
		System.out.println("長 " + box.getLength());
		System.out.println("寬 " + box.getWidth());
		System.out.println("..................................");

		Scanner scanner3 = new Scanner(System.in);
		System.out.print("輸入 length");
		double q = scanner3.nextDouble(); // 讀取輸入數字
		Scanner scanner4 = new Scanner(System.in);
		System.out.print("輸入 width");
		double e = scanner4.nextDouble(); // 讀取輸入數字
		Scanner scanner5 = new Scanner(System.in);
		System.out.print("輸入 height");
		double w = scanner5.nextDouble(); // 讀取輸入數字
		box.setValues(q, e, w);

		System.out.println("長 " + box.getLength());
		System.out.println("寬 " + box.getWidth());
		System.out.println("高 " + box.getHeight());
		System.out.println("..................................");

	}

}
