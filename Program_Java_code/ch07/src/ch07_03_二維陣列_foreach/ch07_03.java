package ch07_03_¤Gºû°}¦C_foreach;

public class ch07_03 {

	public static void main(String[] args) {
/////////////////////////////////////////////////////////////////////////////		
		int[][] x = { { 70, 80 }, { 90, 95 }, { 75, 73 } };
		
		x[0][1] = 100;
		int total_score = 0;
		int single_score = 0;
		
		// ¨«³X foreach
		for (int[] matrix1 : x) {
			single_score = 0;
			for (int element : matrix1) {
				System.out.print(element + " ");
				single_score += element;
				total_score += element;
			}
			System.out.print("\n");
			System.out.println("single_score is " + single_score);
		}
		System.out.println("total_score is " + total_score);
/////////////////////////////////////////////////////////////////////////////
	}

}
