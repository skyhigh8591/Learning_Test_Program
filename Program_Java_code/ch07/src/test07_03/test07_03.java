package test07_03;

import java.util.Scanner;

public class test07_03 {

	public static void main(String[] args) {
		
		int[] arr = {10,20,30,40,50,60,70,80,90};
		int flag = 0;
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("請輸入搜尋數字");
		int z = scanner.nextInt(); // 讀取輸入數字
		
		for(int i=0;i<9;i++)
		{
			if(arr[i]==z)
			{
				System.out.print("found it!"+ "arr[" + i + "]" +  arr[i] + "\n");
				flag=1;
			}
			
		}
		if(flag==0)
		{
			System.out.print("Not found!\n");
		}
		else
		{
			System.out.print("found!\n");

		
	}

	}
}
