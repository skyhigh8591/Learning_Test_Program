package ch06_01_for°j°é;

public class ch06_01 {

	public static void main(String[] args) {
		int sum1;
		sum1 = 1+2+3+4+5+6+7+8+9+10;
		System.out.println("total=" + sum1);
		
		//1+2+...+10
		int sum2 = 0;
		for(int i=1 ; i<=10; i++) {
			
			//sum2 = sum2 + i
			System.out.println(i);
			sum2 += i ;
		
		}
		System.out.println("total=" + sum2);
		
		
		//1+3+5+7+9
		int sum3 = 0;
		for (int i=1 ; i<=9 ; i+=2){
			System.out.println(i);
			sum3 += i;	
		}
		System.out.println("total=" + sum3);
		
		
		//11+9+7+5+3+1
		
		int sum4 = 0;
		for (int i=11 ; i>=1 ; i-=2){
			System.out.println(i);
			sum4 += i;	
		}
		System.out.println("total=" + sum4);
		
		
		

	}

}
