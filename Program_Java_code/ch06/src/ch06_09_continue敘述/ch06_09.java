package ch06_09_continue±Ô­z;

public class ch06_09 {

	public static void main(String[] args) {
		//1+3+5+7....+10
		//1+2+3+4+5
		int sum = 0 ;
		for (int i=0 ; i<=10 ; i++)
		{
			if(i%2==0) {
				continue;
			}
			sum += i;
		}
			System.out.println("1-10©_¼Æ©M¬O:" + sum);
	}

}
