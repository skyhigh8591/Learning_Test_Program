package ch07_04_�x�}�[�k;

public class ch07_04 {

	public static void main(String[] args) {
////////////////////////////////////////////
		
		//�x�}�ۥ[
		int[][] x = {{1,3},{1,0},{1,2}};
		int[][] y = {{0,0},{7,5},{2,1}};
		
		
		//int[][] z = new int[3][2];
		int[][] z = new int[x.length][x[0].length];
		
		//���X �x�}�ۥ[
		for(int i=0 ; i<x.length;i++) {
			for(int j=0 ; j<x[i].length ; j++) {
				z[i][j] = x[i][j] + y[i][j];
			}
		}


		//���X
		for(int i=0 ; i<x.length;i++) {
			for(int j=0 ; j<x[i].length ; j++) {
				System.out.print(z[i][j] + " ");
			}
			System.out.print("\n");
		}
		
		
		System.out.print("\n");
		System.out.print("\n");
		//ckeck z with foreach
		
		for(int[] matrix1:z) {
			for(int element:matrix1) {
				System.out.print(element + " ");
			}
			System.out.print("\n");
		}
		
		
		
		
		
		
		
//////////////////////////////////////////////		
	}

}
