package test05_04;

import java.util.Scanner;

public class test05_04 {

	public static void main(String[] args) {
		int i;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("��J����");
		i = scanner1.nextInt();
		
		if(i%2==0) {
			System.out.print("����");
		}
		else {
			System.out.print("�_��");
		}

		
		switch (i%2) {
		case 1:
			System.out.print("�_��");
			break;
		default:
			System.out.print("����");
		
		
		
		
		}
		
		
		
		
		
		
		
		
	}

}



