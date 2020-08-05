package ch08_fun_02_陣列的傳遞機制;

public class ch08_fun_02 {

	public static void largest(int arr[]) {
		
		int max = arr[0];
		for (int i=1 ; i<arr.length ; i++) {
			
			if(max<arr[i]) {
				max = arr[i];
			}
		}
		System.out.print(" largest num= " + max );
	}

	public static void print_mat(int arr[][]) {

		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j] + " ");

			}
			System.out.print("\n");
		}
		
	}



	public static void main(String[] args) {
		int score[] = { 9, 14, 6, 18, 2, 10 };// 1*6
		largest(score);
		int score2[] = { 90, 140, 6, 18, 1, 0 };// 1*6
		largest(score2);
		
		
		int matrix[][] = {{18,36,32,40},{1,2,3,4}};
		print_mat(matrix);
		
		int matrix1[][] = {{18,100,36,32,40},{11,21,31,41,10}};
		print_mat(matrix1);


	}

}
