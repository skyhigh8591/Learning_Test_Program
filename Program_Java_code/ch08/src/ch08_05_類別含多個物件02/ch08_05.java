package ch08_05_���O�t�h�Ӫ���02;

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
		
		System.out.println("�Ʀr��" + num1);
		Circle C = new Circle();
		C.Radius = num1;
		//System.out.println("area = " + C.Area());
		//System.out.println("area = " + Double.toString(C.Area()));
		double circle_area = C.Area();
		System.out.println("area = " + Double.toString(circle_area));
		
		
		// Double.toString(C.Area()) �Ʀr��r�� �I�s �{��
		
		

	}

}
