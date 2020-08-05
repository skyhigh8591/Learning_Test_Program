package test07_05;

public class test07_05 {

	public static void main(String[] args) {

		int[][] id = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };

		String[][] name = { { "aa" }, { "bb" }, { "cc" }, { "dd" }, { "ee" } };

		double[][] grade = { { 84, 92.5, 76.5, 0, 0, 0 ,0}, { 82.5, 83, 66, 0, 0, 0 ,0}, { 85, 81, 66, 0, 0, 0 ,0},
				{ 74.5, 86, 67, 0, 0, 0,0 }, { 79, 84.5, 72, 0, 0, 0, 0 } };

		String[][] na = new String[2][2];
		double temp[][] = new double[4][5];
		double[][] total = new double[5][1];
		double[][] average = new double[5][1];
		int w = 1;
		for (int i = 0; i <= 0; i++) {
			for (int j = 0; j <= 4; j++) {
				for (int z = 0; z <= 2; z++) {
					total[j][i] = total[j][i] + grade[j][z];
				}
				grade[j][3] = total[j][i];
				grade[j][4] = total[j][i] / 3;
//				grade[j][5] = w;
				w = w + 1;
			}
		}
		
		for (int z = 0; z < 5; z++) {
			int x = 1;
		for (int i = 0; i < 5; i++) {
			if (grade[z][4] < grade[i][4]) {
				x++;
			}
			grade[z][5]=x;
		}
	}
		
		
		
		
	//////////////////////////////////////////////////////	
//		for (int z = 0; z < 5; z++) {
//		for (int i = 0; i < 4; i++) {
//			grade[z][6] = grade[z][4];
//			
//		}
//	}	
//		for (int z = 0; z < 8; z++) {
//		for (int i = 0; i < 4; i++) {
//			if (grade[i][6] < grade[i + 1][6]) {
//				for (int j = 0; j < 5; j++) {
//					temp[0][1] = grade[i + 1][6];
//					temp[1][1] = grade[i][6];
//					grade[i][6] = temp[0][1];
//					grade[i + 1][6] = temp[1][1];
//				}
//			}
//		}
//	}	
//		for (int z = 0; z < 5; z++) {
//		for (int i = 0; i < 5; i++) {
//			if (grade[z][6] == grade[i][4]) {
//				grade[i][5] = z+1;
//				}
//			}
//		}
	/////////////////////////////////////////////////////////////
		
	
		
		for (int z = 0; z < 8; z++) {
			for (int i = 0; i < 4; i++) {
				if (grade[i][3] < grade[i + 1][3]) {
					for (int j = 0; j < 5; j++) {
						temp[0][j] = grade[i + 1][j];
						temp[1][j] = grade[i][j];
						na[0][1] = name[i + 1][0];
						na[1][1] = name[i][0];
						grade[i][j] = temp[0][j];
						grade[i + 1][j] = temp[1][j];
						name[i][0] = na[0][1];
						name[i + 1][0] = na[1][1];
					}
				}
			}
		}
		
		for (int i = 0; i <= 4; i++) {
			System.out.print(id[i][0] + " ");
			System.out.print(name[i][0] + " ");
			for (int j = 0; j <= 5; j++) {
				System.out.printf("%.2f  ", grade[i][j]);
			}
			System.out.print("\n");
		}
//////////////////////////////////////////////////////////////////////
	}

}
