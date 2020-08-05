package ch08_fun_05_遞迴的認識;

public class ch08_fun_05 {

	public static void main(String[] args) {
		int sum = 1 ;
		//5*4*3*2*1
		for(int i = 5 ; i>=1 ; i--)
		{
			sum = sum * i ;
		}
		System.out.println("5*4*3*2*1=" + sum);

		//使用
		System.out.println("5*4*3*2*1=" + fac(5));
		
	}

	
	public static int fac(int n)
	{
		if(n==0)
		{
			return 1;
		}
		else
		{
			return n * fac(n-1);
		}
	}
	
	
	
}
