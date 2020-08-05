package ch07_02_二維陣列;

public class ch07_02 {

	public static void main(String[] args) {
//////////////////////////////////////////////////////////
		
		//第一種
		int[][] x;
		x = new int[3][2];
		
		//第二種
//		int [][] x1 = new int[3][2];
		
		x[0][0] = 70;
		x[0][1] = 80;
		x[1][0] = 90;
		x[1][1] = 95;
		x[2][0] = 75;
		x[2][1] = 73;
		
		
		//修改
		x[0][1] = 100;
		
		//走訪
			
//		System.out.println(x.length);
//		System.out.println(x[0].length);
//
//		
//		for(int i=0 ; i< x.length ; i++) {
//			for(int j=0 ; j< x[i].length ; j++) {
//				System.out.print(x[i][j] + " ");//x[0][0] x[0][1] x[1][0] 
//			}
//			
//			System.out.print("\n");
//		}
		
		int total_score = 0;
		int single_score = 0;
		for (int i = 0; i < x.length; i++) {
			single_score = 0;
					for(int j=0 ; j< x[i].length ; j++) {
			System.out.print(x[i][j] + " ");
			single_score += x[i][j];
			total_score += x[i][j];
					}
			System.out.print("\n");
			System.out.println("single_score is " + single_score);
		}
		
		System.out.println("total_score is " + total_score);

		
		
		
		
		
		
		
//////////////////////////////////////////////////////////		
	}

}
