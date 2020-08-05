package test04_01;

import java.util.Scanner;

public class test04_01 {

	public static void main(String[] args) {
		int x1, x2, x3, x4;
		Scanner scanner1 = new Scanner(System.in);
		System.out.println("輸入三科成績");
		System.out.println("科目一");
		x1 = scanner1.nextInt();
		System.out.println("科目二");
		x2 = scanner1.nextInt();
		System.out.println("科目三");
		x3 = scanner1.nextInt();
        x4 = (x1 + x2 + x3) / 3;
        System.out.println("平均成績" + x4);
        
        double KG1, T2, ALL3,T3;
		Scanner scanner2 = new Scanner(System.in);
		System.out.println("計算BMI");
		System.out.println("輸入體重");
		KG1 = scanner2.nextDouble();
		System.out.println("輸入身高");
		T2 = scanner2.nextDouble();
		T3 = T2/100;
        ALL3 = KG1 / (T3*T3);
        System.out.println("BMI:" + ALL3);
        
        
        
	}

}
