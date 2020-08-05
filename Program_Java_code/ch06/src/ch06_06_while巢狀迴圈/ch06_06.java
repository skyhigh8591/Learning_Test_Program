package ch06_06_while±_ª¬°j°é;

public class ch06_06 {

	public static void main(String[] args) {
//		int i,j;
//		for ( i=1 ; i<=9 ; i++) {
//			for( j=1 ; j<=9 ; j++) {
//				System.out.printf("%d*%d=%d  ",i,j,(i*j));
//			}
//			System.out.printf("\n");
//		}
		
		int i,j;
		i=1;j=1;
		while(i<=9) {
			while(j<=9) {
				System.out.printf("%d*%d=%d  ",i,j,(i*j));
				j++;
			}
			System.out.printf("\n");
			i++;
			j=1;
		}

	}

}
