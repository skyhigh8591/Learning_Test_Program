package test04_01;

import java.util.Scanner;

public class test04_01 {

	public static void main(String[] args) {
		int x1, x2, x3, x4;
		Scanner scanner1 = new Scanner(System.in);
		System.out.println("��J�T�즨�Z");
		System.out.println("��ؤ@");
		x1 = scanner1.nextInt();
		System.out.println("��ؤG");
		x2 = scanner1.nextInt();
		System.out.println("��ؤT");
		x3 = scanner1.nextInt();
        x4 = (x1 + x2 + x3) / 3;
        System.out.println("�������Z" + x4);
        
        double KG1, T2, ALL3,T3;
		Scanner scanner2 = new Scanner(System.in);
		System.out.println("�p��BMI");
		System.out.println("��J�魫");
		KG1 = scanner2.nextDouble();
		System.out.println("��J����");
		T2 = scanner2.nextDouble();
		T3 = T2/100;
        ALL3 = KG1 / (T3*T3);
        System.out.println("BMI:" + ALL3);
        
        
        
	}

}
