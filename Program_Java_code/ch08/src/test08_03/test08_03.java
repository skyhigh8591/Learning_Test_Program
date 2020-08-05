package test08_03;

public class test08_03 {

	public static void main(String[] args) {
		// orignial
		int[] matrix = new int[] { 75, 29, 10, 38, 45,16 };
		int[] return_array =  add(matrix);
		System.out.println("最小值" + return_array[0] );
		System.out.println("最大值" + return_array[5] );
		
	}

	
	public static int[] add(int[] nums) {
		int sum = 0;
		int som = 0;
		for (int z = 0; z < 5; z++) {
			for (int i = 0; i < nums.length - 1; i++) {
				if (nums[i] > nums[i + 1]) {
					sum = nums[i];
					nums[i] = nums[i + 1];
					nums[i + 1] = sum;
				}
			}
		}
		
		
		int [] som1 = new int[6];
		for (int i = 0; i < nums.length; i++)
		{
			som1[i]=nums[i];
		}

		
		return som1;
		
	}
	
	
}
