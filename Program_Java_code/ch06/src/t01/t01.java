package t01;

import java.util.Scanner;

public class t01 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str;
		int num;
		System.out.println("請輸入文字");
		str = scn.nextLine();
		
		if(str.equals("Q")||str.equals("q")) {
			System.out.println("離開");
				}
		else {
			num = Integer.valueOf(str);//字串數字
			System.out.println(num);
		}
		
//////////////////////////////////////////////////////////////		
		
		if(str.equals("Q")||str.equals("q")) {
			System.out.println("離開");
				}
		else {
			try {
			num = Integer.valueOf(str);//字串數字
			System.out.println(num);
			}catch(NumberFormatException e) {
				System.out.println("請輸入 q or Q");
			}
		}
		
		
		
///////////////////////////////////////////////////////////////
	}

}
