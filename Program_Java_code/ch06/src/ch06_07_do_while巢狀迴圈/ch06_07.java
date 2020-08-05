package ch06_07_do_while±_ª¬°j°é;

public class ch06_07 {

	public static void main(String[] args) {
		int i , j;
		i = 1;
		j = 1;
		do {
			do {
				System.out.printf("%d*%d=%2d  ",i,j,(i*j));
				j++;
			}while(j<=9);
			i++;
			j=1;
			System.out.printf("\n");
		}while(i<=9);

	}

}
