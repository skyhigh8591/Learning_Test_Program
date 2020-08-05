package test08_01;






public class test08_01 {

	
	public static void main(String[] args) {
		//orignial
		int[] matrix = new int[] {8,6,9,12,47,55,10};
		System.out.println(add(matrix));
		}

	
	public static int add(int[] nums)
	{
		int sum = 0;
		for(int num:nums)
		{
			if(num%2==1)
			{
				sum = sum + 1 ;
			}			
		}
		return sum;
	}

}
