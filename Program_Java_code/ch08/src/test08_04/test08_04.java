package test08_04;

public class test08_04 {

	public static void main(String[] args) {
		// orignial
		int[][] matrix = new int[][] {{ 2,4,6 },{1,3,5},{8,9,10}};	
		System.out.printf("¥­§¡¼Æ%.3f",add(matrix) );				
	}

	
	public static double add(int[][] nums) {
		double sum = 0;
		double som = 0;
		for (int z = 0; z < nums.length; z++) {
			for (int i = 0; i < nums[z].length; i++) {
					sum = sum + nums[i][z];
					som = som + 1;
			}
		}
		
		
		sum = sum/som;

		
		return sum;
		
	}

}
