package ch08_05_類別含多個物件02;

import java.util.Scanner;

class Circle{
	
	public int Radius;
	
	public double Area() {	
		
		double PI = 3.14 ;
		return PI*Radius*Radius;	
		
	}	
}




public class ch08_05 {

	public static void main(String[] args) {
		
		int num1;
		Scanner scanner = new Scanner(System.in);
		num1 = scanner.nextInt();
		
		System.out.println("數字為" + num1);
		Circle C = new Circle();
		C.Radius = num1;
		//System.out.println("area = " + C.Area());
		//System.out.println("area = " + Double.toString(C.Area()));
		double circle_area = C.Area();
		System.out.println("area = " + Double.toString(circle_area));
		
		
		// Double.toString(C.Area()) 數字轉字串 呼叫 程式
		
		

	}

}
