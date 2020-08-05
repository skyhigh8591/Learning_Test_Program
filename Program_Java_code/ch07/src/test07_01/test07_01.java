package test07_01;

public class test07_01 {

	public static void main(String[] args) {

		int[] arr = { 8,3,5,4,6 };
		int[][] temp = new int[2][5];

//		for (int i = 0; i < arr.length; i++) {
//			for (int j = 0; j < arr.length - 1; j++) {
//				if (arr[j] < arr[j + 1]) { // 相鄰元素兩兩對比
//					int temp; // 元素交換
//					temp = arr[j + 1];
//					arr[j + 1] = arr[j];
//					arr[j] = temp;
//
//				}
//
//			}
//		}

		
			for (int i = 0; i < 1; i++) {
				
					for (int j = 0; j < 5 -1; j++) {
					if (arr[j] > arr[j + 1]) {
						temp[0][j] = arr[j + 1];
						temp[1][j] = arr[j];
						arr[j] = temp[0][j];
						arr[j + 1] = temp[1][j];
					}
				}
			}
		
		
		
		
		
		
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
			System.out.print("\n");

		}

	}

}