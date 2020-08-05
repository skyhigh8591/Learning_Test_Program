package ch03_02_println_vs_print_vs_printf_函數;

public class ch03_02 {

	public static void main(String[] args) {
		// int i = 4; //整數
		// double j = 5;

		int i;
		double j;
		i = 4;
		j = 5;

		// print
		System.out.print("輸出i=" + i + "\n");
		System.out.print("輸出j=" + j + "\n");

		// println 自動換行
		System.out.println("輸出i=" + i);
		System.out.println("輸出j=" + j);

		// printf
		System.out.printf("輸出i=%d\n", i);
		System.out.printf("輸出j=%f\n", j);
		System.out.printf("輸出i=%d,輸出j=%f\n", i, j);
		
	}

}
