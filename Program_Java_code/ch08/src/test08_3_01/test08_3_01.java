package test08_3_01;


import java.util.Scanner;



class Trapezoid{
	
	public double TW;
	public double DW;
	public double T;
	
	public double Area() {	
		
		return ((TW+DW)*T)/2;	
		
	}	
}



public class test08_3_01 {

	public static void main(String[] args) {
		double num1;
		double num2;
		double num3;
		
		
		System.out.println("�п�J�W��");
		Scanner scanner = new Scanner(System.in);
		num1 = scanner.nextInt();
		System.out.println("�п�J�U��");
		Scanner scanner2 = new Scanner(System.in);
		num2 = scanner2.nextInt();
		System.out.println("�п�J��");
		Scanner scanner3 = new Scanner(System.in);
		num3 = scanner3.nextInt();
						
		System.out.println("�W����" + num1 + "�U����" + num2 + "����" + num3);
		Trapezoid C = new Trapezoid();
		C.TW = num1;
		C.DW = num2;
		C.T = num3;
		
		double Trapezoid_Area = C.Area();
		System.out.println("area = " + Double.toString(Trapezoid_Area));
		
		
		// Double.toString(C.Area()) �Ʀr��r�� �I�s �{��
		
		
	}
}

