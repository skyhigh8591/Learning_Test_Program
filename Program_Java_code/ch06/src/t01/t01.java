package t01;

import java.util.Scanner;

public class t01 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str;
		int num;
		System.out.println("�п�J��r");
		str = scn.nextLine();
		
		if(str.equals("Q")||str.equals("q")) {
			System.out.println("���}");
				}
		else {
			num = Integer.valueOf(str);//�r��Ʀr
			System.out.println(num);
		}
		
//////////////////////////////////////////////////////////////		
		
		if(str.equals("Q")||str.equals("q")) {
			System.out.println("���}");
				}
		else {
			try {
			num = Integer.valueOf(str);//�r��Ʀr
			System.out.println(num);
			}catch(NumberFormatException e) {
				System.out.println("�п�J q or Q");
			}
		}
		
		
		
///////////////////////////////////////////////////////////////
	}

}
