package test07_02;

import java.util.Scanner;

public class test07_02 {

	public static void main(String[] args) {
		int[] arr = new int[9];
		int z = 0;
		while(z<9) {	
		Scanner scanner = new Scanner(System.in);
		System.out.print("請輸入第" + z + "個數字");
		int st = scanner.nextInt(); // 讀取輸入數字
		arr[z]= st;
		z++;
		}
		
	
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) { 
					int temp; 
					temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;

				}

			}
		}

		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
			System.out.print("\n");

		}
		
		
		
		
		
		
	}

}
