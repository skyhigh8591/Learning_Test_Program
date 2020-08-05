package ch06_02_while°j°é;

public class ch06_02 {

	public static void main(String[] args) {
		//1+2+3+4+5+6+7+8+9+10
		int i = 1;
		int sum2 = 0;
		while(i<=10)
		{
			sum2 += i;
			i++;
		}
		System.out.println("total sum2 =" + sum2);
		
		
		//1+3+5+7+9
		
		int i2 = 1;
		int sum3 = 0;
		while(i2<=10)
		{
			sum3 += i2;
			i2 = i2 + 2;
		}
		System.out.println("total sum3 =" + sum3);
		
		//11+9+7+5+3+1
		
		
		int i3 = 11;
		int sum4 = 0;
		while(i3>=1)
		{
			sum4 += i3;
			i3 = i3 - 2;
		}
		System.out.println("total sum4 =" + sum4);
		
		
		
		
	}

}
