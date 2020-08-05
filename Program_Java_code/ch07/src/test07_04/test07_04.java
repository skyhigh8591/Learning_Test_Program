package test07_04;

public class test07_04 {

	public static void main(String[] args) {
		int[][] arr = new int[5][7];
		for (int x = 0; x <= 4; x++) {
			for (int i = 0; i <= 6; i++) {
				arr[x][i] = (int) (Math.random() * 7) + 1;
				for (int j = 0; j < i; j++) {
					if (arr[x][j] == arr[x][i]) {
						i--;
						break;
					}
				}
			}
		}
		for (int x = 0; x <= 4; x++) {
			for (int i = 0; i <= 6; i++) {
				System.out.print(arr[x][i] + " ");
			}
			System.out.print("\n");
		}
	}

}
