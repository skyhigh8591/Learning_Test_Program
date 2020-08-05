package exam_01;

public class exam_01 {

	public static void main(String[] args) {
		
		System.out.println(min(20,-30,100));

	}
	
	
	public static int min(int a,int b, int c)
	{
		int z ;
		if(a<b)
		{
			z=a;
		}
		else
		{
			z=b;
		}
		
		if(z<c)
		{
			return z;
		}
		else
		{
			return c;
		}
		
	}

}


