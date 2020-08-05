package ch08_10_°Î¦W°}¦C;

public class ch08_10 {

	public static void main(String[] args) {
		//orignial
//		int[] matrix = new int[] {1 , 2 , 3 , 4 , 5};
//		System.out.println(add(matrix));
		
		//anonymous
		System.out.println(add(new int[] {1,2,3,4,5}));
		
		}

	
	public static int add(int[] nums)
	{
		int sum = 0;
		for(int num:nums)
		{
			sum+=num;
		}
		return sum;
	}
	

}
